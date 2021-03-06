//============================================================================
// Name        : Assignment_3.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

class node
{
    int data;
    node *left,*right;
    int lbit,rbit;
public:
    node(int x)
    {
        data = x;
        left = right = NULL;
        lbit = rbit = 0;
    }
    friend class TBT;
};

class TBT
{
    node* root;
public:
    TBT()
    {
        root = new node(-1);
        root->left = root->right = root;
        root->lbit = 0;
        root->rbit = 1;
    }
    void create();
    void linsert(node*,node*);
    void rinsert(node*,node*);
    node* insuc(node*);
    void inorder();
    void preorder();
};

void TBT::create()
{
	queue <node*> q;
	q.push(root);
	node *p, *temp;
	int x;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		cout << "Left of " <<  temp->data << " :";
		cin >> x;
		if(x != -1)
		{
			p = new node(x);
			linsert(temp,p);
			q.push(p);
		}
		if(temp != root)
		{
			cout << "Right of " <<  temp->data << " :";
			cin >> x;
			if(x != -1)
			{
				p = new node(x);
				rinsert(temp,p);
				q.push(p);
			}
		}
	}
}

void TBT::linsert(node* s,node* t)
{
	t->left = s->left;
	t->lbit = s->lbit;
	t->right = s;
	t->rbit = 0;
	s->left = t;
	s->lbit = 1;
}

void TBT::rinsert(node* s,node* t)
{
	t->right = s->right;
	t->rbit = s->rbit;
	t->left = s;
	t->lbit = 0;
	s->right = t;
	s->rbit = 1;
}

node* TBT::insuc(node* x)
{
	node* s = x->right;
	if(x->rbit == 1)
	{
		while(s->lbit == 1)
		{
			s = s->left;
		}
	}
	return s;
}

void TBT::inorder()
{
	node* T = root;
	while(1)
	{
		T = insuc(T);
		if(T == root)
		{
			return;
		}
		cout << T->data << " ";
	}
}

void TBT::preorder()
{
	int flag = 1;
	node* p = root->left;
	while(p != root)
	{
		while(flag != 0)
		{
			cout << p->data << " ";
			if(p->lbit == 1)
			{
				p = p->left;
			}
			else
			{
				break;
			}
		}
		flag = p->rbit;
		p = p->right;
	}
}
int main()
{
	TBT t;
	t.create();
        t.inorder();
        t.preorder();
}
