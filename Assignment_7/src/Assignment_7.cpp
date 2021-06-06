//============================================================================
// Name        : Assignment_7.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 26

class node
{
	char symbol[10];
	string attribute;
public:
	node(char* k)
	{
		strcpy(symbol, k);
		cout << "Attribute: ";
		getline(cin, attribute);
	}
	void show()
	{
		cout << symbol << "\t" << attribute << "\t";
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
	int ifpresent(int,char*);
	int full();
};

int Hash::full()
{
    int i;
    for(i=0;i<MAX && arr[i] != NULL;i++);
    if(i == MAX)
    {
        return 1;
    }
    return 0;
}

int Hash::ifpresent(int x,char* t)
{
	while(arr[x]->symbol[0] != t[0])
	{
		if(arr[x] == NULL)
		{
			return 0;
		}
		x++;
	}
	return x;
}

void Hash::create_wo_rep(int n)
{
	char str[10];
	for(int i=0;i<n && !full();i++)
    {
        cout << "Symbol: ";
        cin.getline(str, 10);
        if(arr[(int) str[0] - 97] == NULL)
        {
            arr[(int) str[0] - 97] = new node(str);
        }
        else
        {
            char* temp = arr[(int)str[0]-97]->symbol;
            int j = (int) str[0] - 97;
            int o = (int) str[0] - 97;
            while(chain[j] != -1)
            {
                j = chain[j];
            }
            int p = j;
            while (arr[j] != NULL)
            {
                //j++;
                j = (j+1)%MAX;
            }
            arr[j] = new node(str);
            if(str[0] == temp[0])
            {
                chain[p] = j;
            }
            else
            {
                if(ifpresent(o,str) != o)
                {
                    p = ifpresent(o,str);
                }
                else
                {
                    p = j;
                }
            }
            chain[p] = j;
        }
    }
}

void Hash::insert_wo_rep()
{
	char str[10];
	cout << "Symbol: ";
	cin.getline(str, 10);
	if(!full())
    {
        if(arr[(int) str[0] - 97] == NULL)
        {
            arr[(int) str[0] - 97] = new node(str);
        }
        else
        {
            char* temp = arr[(int)str[0]-97]->symbol;
            int j = (int) str[0] - 97;
            int o = (int) str[0] - 97;
            while(chain[j] != -1)
            {
                j = chain[j];
            }
            int p = j;
            while (arr[j] != NULL)
            {
                //j++;
                j = (j+1)%MAX;
            }
            arr[j] = new node(str);
            if(str[0] == temp[0])
            {
                chain[p] = j;
            }
            else
            {
                if(ifpresent(o,str) != o)
                {
                    p = ifpresent(o,str);
                }
                else
                {
                    p = j;
                }
            }
            chain[p] = j;
        }
    }
}

void Hash::create_wrep(int n)
{
	char str[10];
	for(int i=0;i<n && !full();i++)
	{
	    cout << "Symbol: ";
		cin.getline(str, 10);
        if(arr[(int)str[0]-97] == NULL)
        {
            arr[(int)str[0]-97] = new node(str);
        }
        else
        {
            char* temp = arr[(int)str[0]-97]->symbol;
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
                    j = (j+1)%MAX;
                }
                arr[j] = new node(str);
                chain[p] = j;
            }
            else
            {
                int j = (int) str[0] - 97;
                int o = j;
                int l = (int) temp[0] - 97;
                //cout << "l: " << l;
                while(chain[l] != j)
                {
                    l = chain[l];
                }
                //cout << "l: " << l;
                while(j != -1 && chain[j] != -1)
                {
                    j = chain[j];
                }
                int p = j;
                while (arr[j] != NULL)
                {
                    j++;
                }
                //cout << "j: " << j;
                arr[j] = arr[o];
                arr[o] = new node(str);
                chain[p] = j;
                chain[o] = -1;
                chain[l] = j;
            }
        }
	}
}

void Hash::insert_wrep()
{
	char str[10];
	cout << "Symbol: ";
	cin.getline(str, 10);
	if(!full())
    {
        if(arr[(int)str[0]-97] == NULL)
        {
            arr[(int)str[0]-97] = new node(str);
        }
        else
        {
            char* temp = arr[(int)str[0]-97]->symbol;
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
                    j = (j+1)%MAX;
                }
                arr[j] = new node(str);
                chain[p] = j;
            }
            else
            {
                int j = (int) str[0] - 97;
                int o = j;
                int l = (int) temp[0] - 97;
                //cout << "l: " << l;
                while(chain[l] != j)
                {
                    l = chain[l];
                }
                //cout << "l: " << l;
                while(j != -1 && chain[j] != -1)
                {
                    j = chain[j];
                }
                int p = j;
                while (arr[j] != NULL)
                {
                    j++;
                }
                //cout << "j: " << j;
                arr[j] = arr[o];
                arr[o] = new node(str);
                chain[p] = j;
                chain[o] = -1;
                chain[l] = j;
            }
        }
    }
}

void Hash::disp()
{
    cout << "Index\tSymbol\tAttribute\tChain\n";
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] != NULL)
		{
			cout << i << ".\t";
			arr[i]->show();
			cout << chain[i];
			cout << "\n";
		}
	}
}

void Hash::find()
{
	cout << "Enter Symbol to be searched: ";
	char str[10];
	cin.getline(str,8);
	int j = (int) str[0] - 97;
	if(arr[j] == NULL)
	{
		cout << "Symbol not found.\n";
		return;
	}
	int i = -1,flag = 0;
	while(j != -1)
	{
		if(strcmp(arr[j]->symbol,str) == 0)
		{
			flag = 1;
			break;
		}
		i = j;
		j = chain[j];
	}
	if(flag == 0)
	{
		cout << "Symbol not found.\n";
		return;
	}
	if(i != -1)
	{
		chain[i] = chain[j];
	}
	arr[j]->show();
}

void Hash::del()
{
	cout << "Enter Symbol to be deleted: ";
	char str[10];
	cin.getline(str,8);
	int j = (int) str[0] - 97,i = -1,flag = 0;
	while(j != -1)
	{
		if(strcmp(arr[j]->symbol,str) == 0)
		{
			flag = 1;
			break;
		}
		i = j;
		j = chain[j];
	}
    if(flag == 0)
	{
		cout << "Symbol not found.\n";
		return;
	}
    if(i == -1)
    {
        i = j;
        while(chain[j] != -1)
		{
			j = chain[j];
		}
		arr[i] = arr[j];
		chain[i] = chain[j];
		arr[j] = NULL;
    }
    else
    {
        chain[i] = chain[j];
        arr[j] = NULL;
    }
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
		cout << "1. Create Symbol Table.\n";
		cout << "2. Insert into Symbol Table.\n";
		cout << "3. Delete from Symbol Table.\n";
		cout << "4. Find from Symbol Table.\n";
		cout << "5. Display Symbol Table.\n";
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
		cout << "1. Create Symbol Table.\n";
		cout << "2. Insert into Symbol Table.\n";
		cout << "3. Delete from Symbol Table.\n";
		cout << "4. Find from Symbol Table.\n";
		cout << "5. Display Symbol Table.\n";
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
