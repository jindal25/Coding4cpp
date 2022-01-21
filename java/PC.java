class Q{
	int n;
	boolean valueSet = false;

	synchronized int get(){
		try{
			while(!valueSet)
				wait();
		}
		catch (InterruptedException e)
		{
			System.out.println(" Interrupted");
		}
		
		System.out.println(" Got n:" +this.n);
		valueSet = false;
		notify();
		return this.n;
	}

	synchronized void put(int n){
		try{
			while(valueSet)
				wait();
		}
		catch (InterruptedException e)
		{
			System.out.println(" Interrupted");
		}

		System.out.println(" Put n:" +n);
		this.n = n;
		valueSet = true;
		notify();
	}
}

class Producer implements Runnable {
	Q q;
	Thread t;

	Producer(Q q1){
		q = q1;
		t = new Thread(this, "Producer");
	}
	
	public void run(){
		
		int i =0;
		while(true){
			q.put(i++);
		}
	}
	
}

class Consumer implements Runnable{
	Q q;
	Thread t;

	Consumer( Q q){
		this.q=q;
		t = new Thread(this, "Consumer");
	}

	public void run(){
		while(true){
			q.get();
		}
	}
}

class PC{
	public static void main(String[] args){
		Q q = new Q();
		
		Producer p = new Producer(q);
		Consumer c = new Consumer(q);

		p.t.start();
		c.t.start();
	}
}
