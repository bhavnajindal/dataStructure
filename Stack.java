package stack;

public class Stack {
	private int top;
	private int a[];
	
	public Stack(int l)
	{
		top = -1;
		a = new int[l];
	}
	public void push(int x)
	{
		top++;
		a[top] = x; 
	}
	public int pop()
	{
		int y;
		y = a[top];
		top--;
		return y;
	}
	public boolean isfull()
	{
		if(top == a.length-1)
			return true;
		return false;
	}

}
