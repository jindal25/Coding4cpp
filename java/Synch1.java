
class Callme{
	void call(String msg){
		try{
			Thread.sleep(1000);
			System.out.println("[" +msg);
		}
		catch(InterruptedException e){
			System.out.println("Interrupted");
		}
		System.out.println("]");
	}
}

class Caller implements Runnable {
	Callme target;
	String msg;
	Thread t;

	Caller ( Callme targ, String s){
		target = targ;
		msg = s;
		t = new Thread(this);
		System.out.println("Thread id :" +t.getId());
		
	}	

	public void run(){
		synchronized(target){
			System.out.println("Inside synchronised Thread id :" +Thread.currentThread().getId());
			target.call(msg);
		}
	}
}

class Synch1 {
		public static void main(String[] args){
			Callme target = new Callme();
			
			Caller obj1 = new Caller(target, "Hello");
			Caller obj2 = new Caller(target, "World");
			Caller obj3 = new Caller(target, "Synchronised1");
			Caller obj4 = new Caller(target, "Synchronised2");

			obj1.t.start();
			obj2.t.start();
			obj3.t.start();
			obj4.t.start();
			
			//wait for the threads to end 

			try{
				obj1.t.join();
				obj2.t.join();
				obj3.t.join();
				obj4.t.join();
			}
			catch(InterruptedException e){
				System.out.println("Interrupted");
			}
		}
}

