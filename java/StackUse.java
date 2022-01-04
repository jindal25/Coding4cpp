
class Stack{

	int[] stck;
	int tos = -1;

void push(int x){
  	if ( tos >= 10)
     		System.out.println(" underflow");
  	else
     		stck[tos++]=x;
}
	


int pop()
{
 	if (tos > -1)
     		return stck[tos--];
 	else {
     		System.out.println(" underflow");
		return 0;
	}
}

}

public class StackUse{
  	public static void main()
	{
     		System.out.println(" Inside main");

	}
}
