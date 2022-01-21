class NewThread implements Runnable{
	Thread t;
		
	NewThread(){
		t = new Thread(this,"Demo thread");
		System.out.println("Child thread" +t);
	}

	public void run(){
		System.out.println("Child thread Starting ");
		try{
			for( int i = 50 ;i>0;i--){
				System.out.println("Child thread " +i);
				//Thread.sleep(1000);
			}
		}catch(InterruptedException e){
			System.out.println("Child interrupted");
		}
		System.out.println("Child thread exiting ");
	}
}

class ThreadDemoo{
		public static void main(String[] args){
			NewThread nt = new NewThread();
			
			nt.t.start();

			try{
				for( int i = 50 ;i>0;i--){
					System.out.println("Main thread " +i);
					//Thread.sleep(1000);
				}
			}
			catch(InterruptedException e){
				System.out.println("Main interrupted");
			}
			System.out.println("Main thread exiting ");
		}
}



