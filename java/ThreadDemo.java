class ThreadDemo{

	public static void main(String[] args){

		Thread t = Thread.currentThread();

		System.out.println(" Current thread " +t);

		t.setName(" My thread");

		System.out.println(" Current thread after name change " +t);

		try {
			for( int i = 50 ;i>0;i--){
				System.out.println(" n : " +i);
				Thread.sleep(1000);
			}
		}
		catch (InterruptedException e){
			System.out.println("Main thread interrepted");
		}
		
	}
}
