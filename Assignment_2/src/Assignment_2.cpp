//============================================================================
// Name        : Assignment_2.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


class treenode
{
    string key;
    string meaning;
    treenode *left,*right;
public:
    treenode(string s)
    {
        key = s;
        cout << "Meaning: ";
        getline(cin,meaning);
        left = right = NULL;
    }
    treenode(string s,string m)
    {
        key = s;
        meaning = m;
        left = right = NULL;
    }
    friend class BST;
};


class BST
{
    treenode* root;
public:
    BST()
    {
        root = NULL;
    }
    void create();
    treenode* insert(treenode*,string);
    treenode* del_key(treenode*,string);
    treenode* find_min(treenode*);
    void search(string,int&);
    treenode* search_rec(treenode*,string,int&);
    void update(string);
    void operator=(BST);
    treenode* assign_rec(treenode*);
    void in_rec(treenode*);
    void mirror(treenode*);
    void temp();
};

void BST::create()
{
    string s;
    while(1)
    {
        cout << "Data: ";
        getline(cin,s);
        if(s == "-1")
        {
            return;
        }
        root = insert(root,s);
    }
}

treenode* BST::insert(treenode* T,string s)
{
    if(T == NULL)
    {
        T = new treenode(s);
        return T;
    }
    if(s < T->key)
    {
        T->left = insert(T->left,s);
        return T;
    }
    else if(s > T->key)
    {
        T->right = insert(T->right,s);
        return T;
    }
    else
    {
        cout << "Repeat" << endl;
        return T;
    }
}

treenode* BST::del_key(treenode* T, string s)
{
	if(T == NULL)
	{
		cout << "Key not found." << endl;
		return NULL;
	}
	if(s < T->key)
	{
		T->left = del_key(T->left,s);
		return T;
	}
	else if(s > T->key)
	{
		T->right = del_key(T->right,s);
		return T;
	}
	else
	{
		if(T->left == NULL && T->right == NULL)
		{
			delete T;
			return NULL;
		}
		if(T->left == NULL)
		{
			treenode* p = T->right;
			delete T;
			return p;
		}
		if(T->right == NULL)
		{
			treenode* p = T->left;
			delete T;
			return p;
		}
		treenode* p = find_min(T->right);
		T->key = p->key;
		T->right = del_key(T->right,p->key);
		return T;
	}
}

treenode* BST::find_min(treenode* T)
{
	while(T->left != NULL)
	{
		T = T->left;
	}
	return T;
}

void BST::search(string s,int &cnt)
{
    treenode* T = search_rec(root,s,cnt);
    if(T != NULL)
    {
    	cout << "Meaning: " << T->meaning << endl;
    	cout << "No. of searches required: " << cnt << endl;
    	return;
    }
    cout << "Not found" << endl;
}

treenode* BST::search_rec(treenode* T,string s,int& cnt)
{
    if(T == NULL)
    {
        return NULL;
    }
    if(s == T->key)
    {
    	cnt++;
        return T;
    }
    if(s < T->key)
    {
    	cnt++;
        return search_rec(T->left,s,cnt);
    }
    else
    {
    	cnt++;
        return search_rec(T->right,s,cnt);
    }
}

void BST::update(string s)
{
	int cnt = 0;
    treenode* T = search_rec(root,s,cnt);
    getline(cin,s);
    T->meaning = s;
}

void BST::operator=(BST b)
{
	root = assign_rec(b.root);
}

treenode* BST::assign_rec(treenode* T)
{
    if(T != NULL)
    {
        treenode* p = new treenode(T->key,T->meaning);
        p->left = assign_rec(T->left);
        p->right = assign_rec(T->right);
        return p;
    }
    return NULL;
}

void BST::in_rec(treenode* T)
{
    if(T != NULL)
    {
        in_rec(T->left);
        cout << "Key: " << T->key << "\n" << "Meanings: ";
        cout << T->meaning;
        cout << endl;
        in_rec(T->right);
    }
}

void BST::mirror(treenode* T)
{
	if(T != NULL)
	{
		treenode* temp = T->left;
		T->left = T->right;
		T->right = temp;
		mirror(T->left);
		mirror(T->right);
	}
}

void BST::temp()
{
	cout << "1. Create dictionary." << endl;
	cout << "2. Add new keyword into dictionary." << endl;
	cout << "3. Delete a keyword from dictionary." << endl;
	cout << "4. Search in dictionary." << endl;
	cout << "5. Update meaning of a key." << endl;
	cout << "6. Create duplicate of dictionary." << endl;
	cout << "7. Display dictionary in ascending order." << endl;
	cout << "8. Display dictionary in descending order." << endl;
	cout << "9. Exit." << endl;
	int choice;
	string s;
	BST b;
	int cnt = 0;
	while(1)
	{
		cout << "Enter choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cin.ignore(1);
				create();
				break;

			case 2:
				cin.ignore(1);
				cout << "Enter key to be inserted in dictionary: ";
				getline(cin,s);
				root = insert(root,s);
				break;

			case 3:
				cin.ignore(1);
				cout << "Enter key to be deleted from dictionary: ";
				getline(cin,s);
				root = del_key(root,s);
				break;

			case 4:
				cin.ignore(1);
				cout << "Enter key to be searched in dictionary: ";
				getline(cin,s);
				search(s,cnt);
				break;

			case 5:
				cin.ignore(1);
				cout << "Enter key whose meaning is to be updated in dictionary: ";
				getline(cin,s);
				update(s);
				break;

			case 6:
				b = *this;

				break;

			case 7:
				in_rec(root);
				break;

			case 8:
				b = *this;
				mirror(b.root);
				b.in_rec(b.root);
				break;

			case 9:
				return;

			default:
				cout << "Invalid choice." << endl;
				break;
		}
	}
}

int main()
{
    BST a;
    a.temp();
}
