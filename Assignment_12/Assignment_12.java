import java.util.Scanner;

abstract class stack 
{
stack(){}
public final void function()
{
	int flag=0,op,data;
	Scanner obj= new Scanner(System.in);
	while(flag!=1)
	{
		System.out.println("1.Push the element");
		System.out.println("2.Pop the element");
		System.out.println("3.Display element at top");
		System.out.println("4.Exit");
		System.out.println("Enter your choice-:");
		op=obj.nextInt();
		switch(op)
		{
		case 1:
			
			push();
			break;
			
		case 2:
			data=pop();
			if(data!=0)
			{
				System.out.println(" popped");
			}
				
			break;
			
		case 3:
			data=top();
			if(data!=0)
			{
				System.out.print(" is Data at top!!\n");
			}
				
			break;
			
		case 4:
			flag=1;
			break;
			
			default:
				System.out.println("Enter valid choice!!");
				break;
		}
	}
}
abstract void push();
abstract int pop();
abstract int top();
}

class Intstack extends stack
{
	 int[] stack=new int[50];
	 int top=-1;
	int pop()
	{
		RuntimeException re= new RuntimeException("Underflow!!");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				System.out.print(" '" +stack[top--] +"'");
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
			return 0;
		}
	}
	
	
	int top()
	{

		RuntimeException re= new RuntimeException("Underflow!!");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				System.out.println("'" +stack[top] +"'");
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
			return 0;
		}
	}
	
	void push()
	{
		Scanner obj= new Scanner(System.in);
		int x=obj.nextInt();
		try
		{
			RuntimeException re= new RuntimeException("Overflow!!");
			if(top==6)
			{
				throw re;
			}
			else
			{
				stack[++top]=x;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
		}
	}

}


class Charstack extends stack
{
	int top=-1;
	 char[] stck=new char[50];
	int pop()
	{
		RuntimeException re= new RuntimeException("Underflow!!");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				System.out.print("'"+ stck[top--] +"'");
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
			return 0;
		}
	}
	
	
	int top()
	{

		RuntimeException re= new RuntimeException("Underflow!!");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				System.out.print("'"+ stck[top]  +"'");
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
			return 0;
		}
	}
	
	void push()
	{
		Scanner obj= new Scanner(System.in);
		char x=obj.next().charAt(0);
		try
		{
			RuntimeException re= new RuntimeException("Overflow!!");
			if(top==49)
			{
				throw re;
			}
			else
			{
				stck[++top]=x;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
		}
	}

}

class A12
{
	public static void main(String[] args)
	{
		
	System.out.println("-------------For Integer-----------");
	stack t= new Intstack();
	t.function();
	
	
	System.out.println("-------------For Characters-----------");
    	t=new Charstack();
	t.function();
	
	}
}