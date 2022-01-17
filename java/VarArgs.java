class VarArgsDemo{
	
	void Test(int[] v){
		for(int x:v)
			System.out.println(" x: " +x);
	}
		
	void Test1( int ... v){
		for(int x:v)
			System.out.println(" x: " +x);
	}
		
	
}

class VarArgs{
	public static void main(String[] args){
		int[] ar = { 1,2,3,4,5,5,6,7,8,9};
		
		VarArgsDemo va = new VarArgsDemo();
		va.Test(ar);
		
		va.Test1(0,0,1,2,3,4,5,6,7,8,9);
	 	
	}	
}
