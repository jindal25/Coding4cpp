
class Exe{
	static void subr(){
	
	int d ,a;

	//try{
		d =0;
		a= 42/d;
		System.out.println("This would not be printed");
	//}
	//catch(ArithmeticException e){
		System.out.println("Divide by zero exception");
	//}
//	finally{
		System.out.println("This would always be printed");
//	}

	} 
}

class Exec {
	public static void main(String[] args){
	    Exe.subr();
	}
	
}
