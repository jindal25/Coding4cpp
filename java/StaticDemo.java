class StaticName{
	static int a =40;
	static int b= 50;

	StaticName(){
		 a = 100;
		 b = 200;
	}

	static void display(){
		System.out.println(" a : " +a+ " b: " +b);
	}
}

class StaticDemo{
	public static void main(String[] args){
		StaticName.display();
	}
}
