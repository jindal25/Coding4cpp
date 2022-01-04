class Cheese{
	int stickiness;
	
	Cheese(){
		stickiness = 10;
	}

	void changeStickiness()
	{
		stickiness+=1;
	}
	
	void changeStickiness(Cheese c)
	{
		c.stickiness+=1;
		
	}
	
	void PrintCheese()
	{
		System.out.println(" stickinees ; " +this.stickiness);
	}

}

class PassRef{
	public static void main(String[] args)
	{
		Cheese c = new Cheese();
		c.PrintCheese();	
		c.changeStickiness();
		c.changeStickiness();
		c.changeStickiness();
		c.changeStickiness();
		c.changeStickiness();
		c.changeStickiness();
		c.PrintCheese();
		changeStickiness1(c);
		c.PrintCheese();
	}


	static void changeStickiness1(Cheese c){
		c = new Cheese();
		c.changeStickiness();
		c.changeStickiness();
		c.changeStickiness();
		c.changeStickiness();
		c.changeStickiness();
	}
}

