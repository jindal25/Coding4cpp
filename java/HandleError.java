import java.util.Random;

class HandleError{
	public static void main(String[] args){
		int a=0,b=0,c=0;
		Random r = new Random();

		for( int i = 0;i< 32000;i++){		
		try{
			a = r.nextInt();
			b = r.nextInt();
			
			c = 12345 / (a/b);
			System.out.println("checking Divison by zero");
		}
		catch (ArithmeticException e){
			System.out.println("Divison by zero");
			c = 0;
		}

		System.out.println(" c :" +c);
	}
  }
}

