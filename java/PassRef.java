class Test{
	int x;
	int y;
	
	Test(){
		x = -1;
		y = -1;
	}

	Test( int a, int b)
	{
		x = a;
		y = b;
	}

	void meth(Test o)
	{
		o.x=o.x*2;
		o.y=o.y*2;
	}

	void printTest()
	{
		System.out.println(" o.x: " +this.x+ " 0.y: " +this.y);
	}
}

class PassRef{
	public static void main(String[] args)
	{
		Test t = new Test(5,6);
		
		t.printTest();
		t.meth(t);
		t.printTest();

	}

}
