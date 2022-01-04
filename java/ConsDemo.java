class Box{
    int length;
    int hight;
    int width;  

    Box(){
    	length = hight = width = -1;
	}  	

	Box(int a, int b , int c)
	{
		length = a;
        hight = b;
   		width = c;
	}

	Box( int a)
	{
		length = hight = width =a;
	}

	void PrintSides()
	{
		System.out.println(" length : " +length+ " width :" +width+ " height: " +hight);
	}

}

public class ConsDemo{

	public static void main(String[] args)
	{
		Box b = new Box();
		b.PrintSides();
		
		Box b1 = new Box(1,2,3);
		b1.PrintSides();
	
	}
}
