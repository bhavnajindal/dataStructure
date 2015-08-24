package linked_list;

class Node {

	private int data;
	Node next;
	
	public Node(int item)
	{
		data = item;
		next = null;
	}
	int getter()
	{
		return data;
	}
}

public class Linkedlst {
	
	 Node start;
	
	public Linkedlst()
	{
		start = null;
	}
	
	public void insert(int item)
	{
		if(start == null)
		{
			start = new Node(item);
			return;
		}
		else
		{
			Node p = start;
			
			while(p.next != null)
				p = p.next;
			p.next = new Node(item);
		}
	}
	public void print()
	{
		if(start == null)
			System.out.println("list is empty");
		else
		{
			Node p = start;
			
			while(p != null)
			{
				System.out.println(p.getter());
				p = p.next;
			}
		}
	}
	public void print(Node p)
	{
		while(p != null)
	    {
			System.out.println(p.getter());
			p = p.next;
		}
	}
	public Node reverse(Node x)
	{
		Node newHead = null;
		if(x == null)
			return null;
		if(x.next == null)
			return x;
		else
			 newHead = reverse(x.next);
		
		x.next.next = x;
		x.next = null;
		return newHead;
		
	}
}
