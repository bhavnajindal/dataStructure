package queue;
import bst.*;

public class Queue {
	private int left;
	private int right;
	private Node a[];
	private int capacity;
	
	public Queue(int l)
	{
		capacity = l;
		a = new Node[l];
		left = -1;
		right = -1;
	}
	
	public void enque(Node x)
	{
		if(left == right +1)
		{
			System.out.println("sorry queue is full");
		}
		else if(left == 0 && right == capacity - 1)
		{
			System.out.println("sorry queue is full");
		}
		else if(right == capacity - 1)
			right = 0;
		else if(right == -1)
		{
			right++;
			left++;
		}
		else
			right++;
		a[right] = x;
	}
	
	public Node deque()
	{
		Node x = null;
		
		if(left == -1)
		{
			System.out.println("queue underflow");
		}
	    
		x = a[left];
		if(left == right)
			left = right = -1;
		else if(left == capacity - 1)
			left = 0;
		else
			left = left + 1; 
		
		return x;
	}
	public boolean isempty()
	{
		if(left == -1)
			return true;
		else if(left > right)
			return true;
		return false;
	}
	public Node peek()
	{
		Node x = null;
		
		if(!isempty())
		{
			x = a[left];
            return x;
		}
	    return null;
	}
}
