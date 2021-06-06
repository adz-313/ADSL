//============================================================================
// Name        : Assignment_6.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

class node
{
	char key[10];
	string meaning;
public:
	node(char* k)
	{
		strcpy(key, k);
		getline(cin, meaning);
	}
	void show()
	{
		cout << key << " : " << meaning << "\n";
	}
	friend class Hash;
};

class Hash
{
	node* arr[26];
	int chain[26];
public:
	Hash()
	{
		for (int i = 0; i < 26; i++)
		{
			arr[i] = NULL;
			chain[i] = -1;
		}
	}
	void create_wo_rep(int);
	void insert_wo_rep();
	void create_wrep(int);
	void insert_wrep();
	void disp();
	void del();
	void find();
};

void Hash::create_wo_rep(int n)
{
	char str[10];
	for(int i=0;i<n;i++)
	{
		cin.getline(str, 10);
		if(arr[(int) str[0] - 97] == NULL)
		{
			arr[(int) str[0] - 97] = new node(str);
		}
		else
		{
			int j = (int) str[0] - 97;
			while(chain[j] != -1)
			{
				j = chain[j];
			}
			int p = j;
			while (arr[j] != NULL)
			{
				j++;
			}
			arr[j] = new node(str);
			chain[p] = j;
		}
	}
}

void Hash::insert_wo_rep()
{
	char str[10];
	cin.getline(str, 10);
	if(arr[(int) str[0] - 97] == NULL)
	{
		arr[(int) str[0] - 97] = new node(str);
	}
	else
	{
		int j = (int) str[0] - 97;
		while(chain[j] != -1)
		{
			j = chain[j];
		}
		int p = j;
		while (arr[j] != NULL)
		{
			j++;
		}
		arr[j] = new node(str);
		chain[p] = j;
	}
}

void Hash::create_wrep(int n)
{
	char str[10];
	for(int i=0;i<n;i++)
	{
		cin.getline(str, 10);
		if(arr[(int)str[0]-97] == NULL)
		{
			arr[(int)str[0]-97] = new node(str);
		}
		else
		{
			char* temp = arr[(int)str[0]-97]->key;
			if(str[0] == temp[0])
			{
				int j = (int) str[0] - 97;
				while(j != -1 && chain[j] != -1)
				{
					j = chain[j];
				}
				int p = j;
				while (arr[j] != NULL)
				{
					j++;
				}
				arr[j] = new node(str);
				chain[p] = j;
			}
			else
			{
				int j = (int) str[0] - 97;
				int o = j;
				while(j != -1 && chain[j] != -1)
				{
					j = chain[j];
				}
				int p = j;
				while (arr[j] != NULL)
				{
					j++;
				}
				arr[j] = arr[o];
				arr[o] = new node(str);
				chain[p] = j;
				chain[o] = -1;
			}
		}
	}
}

void Hash::insert_wrep()
{
	char str[10];
	cin.getline(str, 10);
	if(arr[(int)str[0]-97] == NULL)
	{
		arr[(int)str[0]-97] = new node(str);
	}
	else
	{
		char* temp = arr[(int)str[0]-97]->key;
		if(str[0] == temp[0])
		{
			int j = (int) str[0] - 97;
			while(j != -1 && chain[j] != -1)
			{
				j = chain[j];
			}
			int p = j;
			while (arr[j] != NULL)
			{
				j++;
			}
			arr[j] = new node(str);
			chain[p] = j;
		}
		else
		{
			int j = (int) str[0] - 97;
			int o = j;
			while(j != -1 && chain[j] != -1)
			{
				j = chain[j];
			}
			int p = j;
			while (arr[j] != NULL)
			{
				j++;
			}
			arr[j] = arr[o];
			arr[o] = new node(str);
			chain[p] = j;
			chain[o] = -1;
		}
	}
}

void Hash::disp()
{
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] != NULL)
		{
			cout << i << ". ";
			arr[i]->show();
			cout << chain[i];
			cout << "\n";
		}
	}
}

void Hash::del()
{
	cout << "Enter key to be deleted: ";
	char str[10];
	cin.getline(str,8);
	int j = (int) str[0] - 97;
	int i = -1,flag = 0;
	while(j != -1)
	{
		if(strcmp(arr[j]->key,str) == 0)
		{
			flag = 1;
			break;
		}
		i = j;
		j = chain[j];
	}
	if(flag == 0)
	{
		cout << "Key not found.\n";
		return;
	}
	if(i != -1)
	{
		chain[i] = chain[j];
	}
	arr[j] = NULL;
}

void Hash::find()
{
	cout << "Enter key to be searched: ";
	char str[10];
	int j = (int) str[0] - 97;
	int i = -1,flag = 0;
	while(j != -1)
	{
		if(strcmp(arr[j]->key,str) == 0)
		{
			flag = 1;
			break;
		}
		i = j;
		j = chain[j];
	}
	if(flag == 0)
	{
		cout << "Key not found.\n";
		return;
	}
	if(i != -1)
	{
		chain[i] = chain[j];
	}
	arr[j]->show();
}

int main()
{
	Hash h;
	int ch,n;
	cout << "1. Without Replacement.\n";
	cout << "2. With Replacement.\n";
	cout << "Enter choice: ";
	cin >> ch;
	if(ch == 1)
	{
		cout << "1. Create Dictionary.\n";
		cout << "2. Insert into Dictionary.\n";
		cout << "3. Delete from Dictionary.\n";
		cout << "4. Find from Dictionary.\n";
		cout << "5. Display Dictionary.\n";
		cout << "6. Exit.\n";
		while(1)
		{
			cout << "Enter choice: ";
			cin >> ch;
			switch(ch)
			{
				case 1:
					cout << "Enter number of Entries: ";
					cin >> n;
					cin.ignore(1);
					h.create_wo_rep(n);
					break;

				case 2:
					cin.ignore(1);
					h.insert_wo_rep();
					break;

				case 3:
					cin.ignore(1);
					h.del();
					break;

				case 4:
					cin.ignore(1);
					h.find();
					break;

				case 5:
					h.disp();
					break;

				case 6:
					return 0;

				default:
					cout << "Invalid choice.\n";
			}
		}
	}
	else
	{
		cout << "1. Create Dictionary.\n";
		cout << "2. Insert into Dictionary.\n";
		cout << "3. Delete from Dictionary.\n";
		cout << "4. Find from Dictionary.\n";
		cout << "5. Display Dictionary.\n";
		cout << "6. Exit.\n";
		while(1)
		{
			cout << "Enter choice: ";
			cin >> ch;
			switch(ch)
			{
				case 1:
					cout << "Enter number of Entries: ";
					cin >> n;
					cin.ignore(1);
					h.create_wrep(n);
					break;

				case 2:
					cin.ignore(1);
					h.insert_wrep();
					break;

				case 3:
					cin.ignore(1);
					h.del();
					break;

				case 4:
					cin.ignore(1);
					h.find();
					break;

				case 5:
					h.disp();
					break;

				case 6:
					return 0;

				default:
				cout << "Invalid choice.\n";
			}
		}
	}
}
