class OverloadDemo{

	void test()
	{
		System.out.println("no parameters");
	}

	/*void test(int a)
	{
		System.out.println("a : " +a);
	}*/


	void test(int a, int b)
	{
		System.out.println("a and b:" +a+ " " +b);
	}

	double test(double a)
	{
		System.out.println("double a:" +a);
		return a*a;
	}
	
	/*void test(double a)
	{
		System.out.println("double a:" +a);
	}*/

}

public class Overload{
	public static void main(String[] args)
	{
		OverloadDemo ob = new OverloadDemo();
		double result;

		//call all verson of test
		ob.test();
		ob.test(1);
		ob.test(3,2);
		result = ob.test(123.25);
		System.out.println("output of double test call:" +result);
	}
}

