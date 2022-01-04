class Test{
	int i;
	Test(int a){
		i=a;
	}
	
	static Test ReturnOb()
	{
		Test t = new Test(110);
		return t;	
	}
	
	void PrintTest()
	{
		System.out.println(" i = : " +i);
	}
}

class RetOb{
	public static void main(String[] args)
	{
		Test t1 =new Test(10);
		t1 = t1.ReturnOb();
		t1.PrintTest();
	}
}
