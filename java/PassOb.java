class MyObject{
	int x;
	int y;

	MyObject(int a, int b)
	{
		x=a;
		y=b;
	}

	boolean equalTo(MyObject obj)
	{
		if ((this.x == obj.x) && ( this.y == obj.y))
			return true;
		else
			return false;
	}
}

class PassOb{
	public static void main(String[] args)
	{
		MyObject myo = new MyObject(1,2);
		MyObject myo1 = new MyObject(1,2);

		System.out.println(" are the two ojbects equal:" +myo.equalTo(myo1));
		
	}	
}
