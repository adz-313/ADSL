package Definition;
import Declaration.Stack;
import java.util.Scanner;
class MyStack implements Stack
{
	int data[];
	int top;
	
	MyStack()
	{
		data = new int[20];
		top = -1;
	}
  
	public boolean full()
	{
		if(top == 19)
			return true;
		return false;
	}
	
	public boolean empty()
	{
		if(top == -1)
			return true;
		return false;
	}
		
	public void push(int x)
	{
		if(!full())
		{
			top++;
			data[top] = x;
		}
	}
	
	public int pop()
	{
		if(!empty())
		{
			int x = data[top];
			top--;
			return x;		
		}
		return -1;
	}
}
class MyClass
{
	public static void main(String[] args)
	{
		MyStack obj = new MyStack();
		while(true)
		{
			System.out.println("1. Push.");
			System.out.println("2. Pop.");
			System.out.println("3. Exit.");
			System.out.println("Enter choice: ");
			Scanner sc = new Scanner(System.in); 
			int choice = sc.nextInt();
			int data;
			switch(choice)
			{
				case 1:
					System.out.println("Enter data: ");
					data = sc.nextInt();
					obj.push(data);
					break;
				case 2:
					data = obj.pop();
					if(data == -1)
					{
						System.out.println("Stack empty.");
					}
					else
					{
						System.out.println(data + " popped.");
					}
					break;
				case 3:
					return;
				default:
					System.out.println("Invalid input.");
			}
		}
	}
}
