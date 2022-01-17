
class A{
   int i= 10; 
   int j= 10;
   private int l = 30;

   A(){
		i = 100;
		j = 100;
		l = 500;
   }   
   void showj(){
	System.out.println("the i :" +i+" j: "+j);
	System.out.println("the l: "+l);
   }

}

class B extends A{
   int k= 20;
   void showk(){
       //showj();
       System.out.println(" k is : "+k);
	} 
    void sum(){
		int sum = i + j + k;
    	System.out.println(" i + j +k :" +sum);
	}
}

class SimpleInheritance{
	public static void main(String[] args){
		A objA = new A();
		B objB = new B();

		objA.showj();
		objB.showk();
		objB.sum();
	}
}
