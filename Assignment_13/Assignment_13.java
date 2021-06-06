import java.util.*;
class MyClass
{
	void arrayListOperations()
	{
		ArrayList<String> arr = new ArrayList<String>();
		while(true)
		{
			System.out.println("1. Add into Array.");
			System.out.println("2. Display Array.");
			System.out.println("3. Delete from Array");
			System.out.println("4. Exit");
			System.out.println("Enter choice: ");
			Scanner sc = new Scanner(System.in);
			int choice,pos;
			try
			{	
				choice = sc.nextInt();
				String str;
				switch(choice)
				{
					case 1:
						System.out.println("Enter String: ");
						str = sc.next();
						arr.add(str);
						break;
					case 2:
						for(String x: arr)
						{		
							System.out.println(x);
						}
						break;
					case 3:				
						System.out.println("Enter String: ");
						str = sc.next();
						arr.remove(str);
						break;
					case 4:
						return;	
					default:
						System.out.println("Invalid Choice.");	
				}
			}
			catch(InputMismatchException e)
			{
				System.out.println("Invalid Input.");
			}
		}
	}
	void linkedListOperations()
	{
		LinkedList<String> ll=new LinkedList<String>();  
		while(true)
		{
			System.out.println("1. Add at Beginning.");
			System.out.println("2. Add at End");
			System.out.println("3. Add at Position");
			System.out.println("4. Delete at Beginning");
			System.out.println("5. Delete at End");
			System.out.println("6. Delete at Position");
			System.out.println("7. Display List");
			System.out.println("8. Exit");
			System.out.println("Enter choice: ");
			Scanner sc = new Scanner(System.in);
			int choice,pos;
			try
			{
				choice = sc.nextInt();
				String str;
				switch(choice)
				{
					case 1:
						System.out.println("Enter String: ");
						str = sc.next();
						ll.addFirst(str);
						break;
					case 2:
						System.out.println("Enter String: ");
						str = sc.next();
						ll.addLast(str);
						break;
					case 3:
						System.out.println("Enter String: ");
						str = sc.next();
						System.out.println("Enter Position: ");
						pos = sc.nextInt();
						ll.add(pos,str);
						break;
					case 4:
						System.out.println(ll.removeFirst()+" deleted from list.");
						break;
					case 5:
						System.out.println(ll.removeLast()+" deleted from list.");
						break;
					case 6:
						System.out.println("Enter Position: ");
						pos = sc.nextInt();
						System.out.println(ll.remove(pos)+" deleted from list.");
						break;
					case 7:	 
						for(String x : ll)
						{
							System.out.println(x);
						}	
						break;		  
					case 8:
						return;	
					default:
						System.out.println("Invalid Choice.");	
				}
			}
			catch(InputMismatchException e)
			{
				System.out.println("Invalid Input.");
			}
			catch(IndexOutOfBoundsException e)
			{
				System.out.println(e);
			}
			catch(NoSuchElementException e)
			{
				System.out.println(e);
			}
		}
	}
	void stackOperations()
	{
		Stack<String> stack = new Stack<String>();
		while(true)
		{
			System.out.println("1. Push");
			System.out.println("2. Pop");
			System.out.println("3. Exit");
			System.out.println("Enter choice: ");
			Scanner sc = new Scanner(System.in);
			int choice;
			try
			{
				choice = sc.nextInt();
				String str;
				switch(choice)
				{
					case 1:
						System.out.println("Enter String: ");
						str = sc.next();
						stack.push(str);
						break;
					case 2:
						System.out.println("Top: "+ stack.pop());
						break;
					case 3:
						return;	
					default:
						System.out.println("Invalid Choice.");	
				}
			}
			catch(InputMismatchException e)
			{
				System.out.println("Invalid Input.");
			}
			catch(EmptyStackException e)
			{
				System.out.println("Stack Empty");
			}
		}	
	}
	void priorityQueueOperations()
	{
		PriorityQueue<String> queue = new PriorityQueue<String>();
		while(true)
		{
			System.out.println("1. Enque");
			System.out.println("2. Deque");
			System.out.println("3. Display");
			System.out.println("4. Exit");
			System.out.println("Enter choice: ");
			Scanner sc = new Scanner(System.in);
			int choice;
			try
			{
				choice = sc.nextInt();
				String str;
				switch(choice)
				{
					case 1:
						System.out.println("Enter String: ");
						str = sc.next();
						queue.add(str);
						break;
					case 2:
						System.out.println(queue.remove());
						break;
					case 3:
						for(String x:queue)
						{
							System.out.println(x);
						}
						break;
					case 4:
						return;	
					default:
						System.out.println("Invalid Choice.");	
				}
			}
			catch(InputMismatchException e)
			{
				System.out.println("Invalid Input.");
			}
			catch(NoSuchElementException e)
			{
				System.out.println(e);
			}
		}	
	}
	void treeSetOperations()
	{
		TreeSet<String> tree=new TreeSet<String>();  
		while(true)
		{
			System.out.println("1. Add to Tree.");
			System.out.println("2. Display Tree.");
			System.out.println("3. Delete from Tree");
			System.out.println("4. Exit");
			System.out.println("Enter choice: ");
			Scanner sc = new Scanner(System.in);
			int choice,pos;
			try
			{	
				choice = sc.nextInt();
				String str;
				switch(choice)
				{
					case 1:
						System.out.println("Enter String: ");
						str = sc.next();
						tree.add(str);
						break;
					case 2:
						for(String x : tree)
						{
							System.out.println(x);
						}
						break;
					case 3:				
						System.out.println("Enter String: ");
						str = sc.next();
						tree.remove(str);
						break;
					case 4:
						return;	
					default:
						System.out.println("Invalid Choice.");	
				}
			}
			catch(InputMismatchException e)
			{
				System.out.println("Invalid Input.");
			}
		}
	}
	public static void main(String[] args)
	{
		MyClass obj = new MyClass();
		System.out.println("1. Array Operations.");
		System.out.println("2. Linked list Operations.");
		System.out.println("3. Stack Operations.");
		System.out.println("4. Priority Queue Operations.");
		System.out.println("5. Tree Set Operations.");
		System.out.println("Enter choice: ");
		Scanner sc = new Scanner(System.in);
		try
		{
			int choice = sc.nextInt();
			switch(choice)
			{
				case 1:	
					obj.arrayListOperations();
					break;
				case 2:
					obj.linkedListOperations();
					break;
				case 3:
					obj.stackOperations();
					break;
				case 4:
					obj.priorityQueueOperations();
					break;
				case 5:
					obj.treeSetOperations();
					break;
				default:
					System.out.println("Invalid choice.");
			}
		}
		catch(InputMismatchException e)
		{
			System.out.println("Invalid Input.");
		}
	}  
}  