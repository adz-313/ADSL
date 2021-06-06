//============================================================================
// Name        : Assignment_1.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define MAX 30

class treenode{
	int data;
	treenode* lchild,*rchild;
public:
	treenode(int x)
	{
		data = x;
		lchild = NULL;
		rchild = NULL;
	}
	friend class tree;
};

struct stacknode
{
    treenode* link;
    int flag;
}typedef stacknode;

class tree
{
	treenode* root;
	treenode* makeTree();
public:
	tree()
	{
		root = NULL;
	}
	void create();
	void disp_level();
	void temp(tree);
	void operator=(tree);
	treenode* assign_rec(treenode*);
	void inorder(treenode*);
	void leaf(treenode*);
	void internal(treenode*);
	void preorder(treenode*);
	void postorder(treenode*);
	int height(treenode*);
	void mirror(treenode*);
	treenode* erase(treenode*);
	void non_rec_in();
	void non_rec_pre();
	void non_rec_post();
	int equal(treenode*,treenode*);
};

treenode* tree::makeTree()
{
	int x;
	cout << "Data: ";
	cin >> x;
	if(x == -1)
	{
		return NULL;
	}
	treenode* temp = new treenode(x);
	cout << "Left of " << temp->data << " : ";
	temp->lchild = makeTree();
	cout << "Right of " << temp->data << " : ";
	temp->rchild = makeTree();
	return temp;
}

void tree::create()
{
	root = makeTree();
}

void tree::inorder(treenode* T)
{
	if(T != NULL)
	{
		inorder(T->lchild);
		cout << T->data << " ";
		inorder(T->rchild);
	}
}

void tree::preorder(treenode* T)
{
	if(T != NULL)
	{
		cout << T->data << " ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

void tree::postorder(treenode* T)
{
	if(T != NULL)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout << T->data << " ";
	}
}

int tree::height(treenode* T)
{
    int x = 0,y = 0;
    if(T != NULL)
    {
        x = height(T->lchild);
        y = height(T->rchild);
        if(x > y)
        {
            return x+1;
        }
        else
        {
            return y+1;
        }
    }
    return 0;
}

treenode* tree::assign_rec(treenode* T)
{
    if(T != NULL)
    {
        treenode* p = new treenode(T->data);
        p->lchild = assign_rec(T->lchild);
        p->rchild = assign_rec(T->rchild);
        return p;
    }
    return NULL;
}

void tree::mirror(treenode* T)
{
    if(T != NULL)
    {
        treenode* temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
        mirror(T->lchild);
        mirror(T->rchild);
    }
}

void tree::non_rec_in()
{
    stack <treenode*> s;
    treenode* T = root;
    while(T != NULL)
    {
        s.push(T);
        T = T->lchild;
    }
    while(!s.empty())
    {
        T = s.top();
        s.pop();
        cout << T->data << " ";
        T = T->rchild;
        while(T != NULL)
        {
            s.push(T);
            T = T->lchild;
        }
    }
}

treenode* tree::erase(treenode* T)
{
    if(T != NULL)
    {
        erase(T->lchild);
        erase(T->rchild);
        delete T;
        return NULL;
    }
}

void tree::disp_level()
{
	queue <treenode*> q;
	q.push(root);
	while(!q.empty())
	{
		treenode* t = q.front();
		q.pop();
		cout << t->data << " ";
		if(t->lchild != NULL)
		{
			q.push(t->lchild);
		}
		if(t->rchild != NULL)
		{
			q.push(t->rchild);
		}
	}
}

void tree::non_rec_pre()
{
    stack <treenode*> s;
    treenode* T = root;
    while(T != NULL)
    {
        cout << T->data << " ";
        s.push(T);
        T = T->lchild;
    }
    while(!s.empty())
    {
        T = s.top();
        s.pop();
        T = T->rchild;
        while(T != NULL)
        {
            cout << T->data << " ";
            s.push(T);
            T = T->lchild;
        }
    }
}

void tree::non_rec_post()
{
    treenode* T = root;
    stack <stacknode> s;
    stacknode st;
    while(T != NULL)
    {
        st.link = T;
        st.flag = 0;
        s.push(st);
        T = T->lchild;
    }
    while(!s.empty())
    {
        st = s.top();
        s.pop();
        if(st.flag == 0)
        {
            st.flag = 1;
            T = st.link;
            s.push(st);
            T = T->rchild;
            while(T != NULL)
            {
                st.link = T;
                st.flag = 0;
                s.push(st);
                T = T->lchild;
            }
        }
        else
        {
            cout << st.link->data << " ";
        }
    }
}

void tree::operator=(tree b)
{
	b.root = assign_rec(root);
}

int tree::equal(treenode* a,treenode* b)
{
	if(a != NULL && b != NULL)
	{
		if(a->data == b->data)
		{
			return equal(a->lchild,b->lchild) * equal(a->rchild,b->rchild);
		}
		else
		{
			return 0;
		}
	}
	if(a != NULL)
    {
        return 0;
    }
    if(b != NULL)
    {
        return 0;
    }
    return 1;
}

void tree::leaf(treenode* T)
{
	if(T != NULL)
	{
		if(T->lchild == NULL && T->rchild == NULL)
		{
			cout << T->data << " ";
		}
		leaf(T->lchild);
		leaf(T->rchild);
	}
}

void tree::internal(treenode* T)
{
    if(T != NULL)
	{
    	if(T->lchild != NULL || T->rchild != NULL)
  	    {
  	        if(T != root)
                cout << T->data << " ";
    	}
		internal(T->lchild);
		internal(T->rchild);
	}
}

void tree::temp(tree b)
{
	tree temp;
	char choice;
	cout << "1. Create binary tree." << endl;
	cout << "2. Assign current tree to another tree." << endl;
	cout << "3. Erase all nodes of tree." << endl;
	cout << "4. Create mirror image of tree." << endl;
	cout << "5. Check if trees are equal." << endl;
	cout << "6. Preorder traversal(r/n)." << endl;
	cout << "7. Inorder traversal(r/n)." << endl;
	cout << "8. Postorder traversal(r/n)." << endl;
	cout << "9. Print leaf nodes." << endl;
	cout << "10. Print internal nodes." << endl;
	cout << "11. Exit." << endl;
	int ch;
	while(1)
	{
	    cout << "Enter choice: ";
        cin >> ch;
		switch(ch)
		{
			case 1:
				create();
				break;

			case 2:
				b = *this;
				cout << "Tree copied." << endl;
				break;

			case 3:
				root = erase(root);
				cout << "Tree Erased." << endl;
				break;

			case 4:
				mirror(root);
				break;

			case 5:
				temp.create();
				if(equal(root,temp.root))
				{
					cout << "Equal." << endl;
				}
				else
				{
					cout << "Not equal." << endl;
				}
				break;

			case 6:
				cout << "Enter choice(r/n): ";
				cin >> choice;
				if(choice == 'n')
				{
					cout << "Non Recursive Preorder: ";
					non_rec_pre();
				}
				if(choice == 'r')
				{
					cout << "Recursive Preorder: ";
					preorder(root);
				}
				cout << endl;
				break;

			case 7:
				cin >> choice;
				if(choice == 'n')
				{
					cout << "Non Recursive Inorder: ";
					non_rec_in();
				}
				if(choice == 'r')
				{
					cout << "Recursive Inorder: ";
					inorder(root);
				}
				cout << endl;
				break;

			case 8:
				cin >> choice;
				if(choice == 'n')
				{
					cout << "Non Recursive Postorder: ";
					non_rec_post();
				}
				if(choice == 'r')
				{
					cout << "Recursive Postorder: ";
					postorder(root);
				}
				cout << endl;
				break;

			case 9:
				cout << "Leaf: ";
				leaf(root);
				cout << endl;
				break;

			case 10:
				cout << "Internal: ";
				internal(root);
				cout << endl;
				break;

			case 11:
				return;
				break;

			default:
				cout << "Invalid choice." << endl;
				break;
		};
	}
}

int main()
{
	tree a,b;
	a.temp(b);
}
