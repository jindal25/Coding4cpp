//Filename CharStack.java 
public class CharStack { // Instance variables:
private char[] stackArray; 
private int topOfStack;
public CharStack(int capacity) 
{ 	
	stackArray = new char[capacity]; 
	topOfStack = -1;
	counter++;
}
// Instance methods:
public void push(char element) 
public char pop()
public char peek()
public boolean isEmpty() 
public boolean isFull()
// The array implementing the stack. // The top of the stack.
// (1) // Constructor now increments the counter for each object created.
// Static variable
private static int counter;
{ stackArray[++topOfStack] = element; } 
{ return stackArray[topOfStack--]; }
{ return stackArray[topOfStack]; }
{ return topOfStack < 0; }
{ return topOfStack == stackArray.length - 1; }
// Static method (3)
public static int getInstanceCount() { return counter; } 
}