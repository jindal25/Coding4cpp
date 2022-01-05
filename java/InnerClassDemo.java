class Outer{
	int x;
	int y;
	
	Outer(){
		x =1;
		y =1;
	}

	void display(){
		Inner in = new Inner();
		in.show();
	}

	void show(){
		System.out.println(" Outer y is " +y);
		System.out.println(" Inner y is " +Inner.y);
	}
	
	class Inner{
		static int y;
		Inner(){
			y = 10;
		}
		void show(){
			System.out.println(" Inner y is " +y);
		}
	}
}

class InnerClassDemo{
	public static void main(String[] arg){
	Outer o = new Outer();
	
	o.display();
	o.show();
	}
}
