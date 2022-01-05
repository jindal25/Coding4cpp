
class Stack{

	private int[] stck;
	private int tos;

	Stack(){
		stck = new int[10];
		tos = -1;
	}

	void push(int x){
  	if ( tos >= stck.length-1 )
     		System.out.println(" underflow");
  	else
     		stck[++tos]=x;
	}
	


	int pop()
	{
 		if (tos >= 0)
     		return stck[tos--];
 		else {
     		System.out.println(" underflow");
			return 0;
		}
	}

}

public class StackUse{
  	public static void main(String[] args)
	{
     		System.out.println(" Inside main");
			Stack s1 = new Stack();
			
			s1.push(1);
			s1.push(2);
			s1.push(4);
			s1.push(3);
			System.out.println("Pop returned :"+s1.pop());
			System.out.println("Pop returned :"+s1.pop());
			System.out.println("Pop returned :"+s1.pop());
			System.out.println("Pop returned :"+s1.pop());


	}
}
