//============================================================================
// Name        : Assignment_4.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class gnode;

class Graph
{
    gnode* ghead;
public:
    Graph()
    {
        ghead = NULL;
    }
    friend class gnode;
    void read();
    void print();
    void add_edge();
    void add_city();
    void del_path();
    void del_city();
    int posn(string);
    void traversal();
    void DFS(string,int[]);
};

class lnode
{
    string dest;
    int fuel;
    lnode* next;
public:
    lnode(string s,int x)
    {
        dest = s;
        fuel = x;
        next = NULL;
    }
    friend class gnode;
    friend void Graph::DFS(string,int[]);
};

class gnode
{
    string source;
    gnode* next;
    lnode* lhead;
public:
    gnode(string s)
    {
        source = s;
        next = NULL;
        lhead = NULL;
    }
    friend class Graph;
    void insert(string,int);
    void show();
    void del(string);
    int dest_pres(string);
};

void gnode::insert(string s,int x)
{
    if(lhead == NULL)
    {
        lhead = new lnode(s,x);
    }
    else
    {
        lnode* p = lhead;
        while(p->next != NULL && p->dest != s)
        {
            p = p->next;
        }
        if(p->next == NULL)
            p->next = new lnode(s,x);
        else
            p->fuel = x;
    }
}

void gnode::show()
{
    lnode* p = lhead;
    while(p != NULL)
    {
        cout << p->dest << " " << p->fuel << endl;
        p = p->next;
    }
}

void gnode::del(string v)
{
    lnode* p = lhead;
    lnode* q = NULL;
    while(p != NULL && p->dest != v)
    {
        q = p;
        p = p->next;
    }
    if(p == NULL)
    {
        cout << "Destination not found.\n";
        return;
    }
    else if(q == NULL)
    {
        lhead = p->next;
        delete p;
    }
    else
    {
        q->next = p->next;
        delete p;
    }
}

int gnode::dest_pres(string v)
{
	lnode* l = lhead;
	while(l != NULL && l->dest != v)
	{
		l = l->next;
	}
	if(l != NULL)
		return 1;
	return 0;
}

void Graph::read()
{
    string u,v;
    int x;
    while(1)
    {
        cout << "Source: ";
        getline(cin,u);
        if(u == "stop")
        {
            return;
        }
        cout << "Destination: ";
        getline(cin,v);
        cout << "Fuel: ";
        cin >> x;
        cin.ignore(1);
        //gnode* p = ghead;
        if(ghead == NULL)
        {
            ghead = new gnode(u);
            ghead->next = new gnode(v);
            ghead->insert(v,x);
        }
        else
        {
            gnode* p = ghead;
            gnode* q;
            while(p != NULL && p->source != u)
            {
                q = p;
                p = p->next;
            }
            if(p == NULL)
            {
                cout << "New source entered.\n";
                q->next = new gnode(u);
                q = q->next;
                q->insert(v,x);
            }
            else
            {
                cout << "Old source entered.\n";
                p->insert(v,x);
            }
            p = ghead;
            q = NULL;
            while(p != NULL && p->source != v)
            {
                q = p;
                p = p->next;
            }
            if(p == NULL)
            {
                q->next = new gnode(v);
            }
        }
    }
}

void Graph::print()
{
    gnode* p = ghead;
    while(p != NULL)
    {
        cout << "source: " << p->source << "\n";
        cout << "destinations: \n";
        p->show();
        p = p->next;
    }
}

void Graph::add_edge()
{
    string u,v;
    int x;
    cout << "Source: ";
    getline(cin,u);
    if(u == "stop")
    {
        return;
    }
    cout << "Destination: ";
    getline(cin,v);
    cout << "Fuel: ";
    cin >> x;
    cin.ignore(1);
    //gnode* p = ghead;
    if(ghead == NULL)
    {
        ghead = new gnode(u);
        ghead->insert(v,x);
    }
    else
    {
        gnode* p = ghead;
        gnode* q;
        while(p != NULL && p->source != u)
        {
            q = p;
            p = p->next;
        }
        if(p == NULL)
        {
            cout << "New source entered.\n";
            char ch;
            cout << "Do you want to add new city?(y/n): ";
            cin >> ch;
            if(ch == 'n')
            {
            	return;
            }
            q->next = new gnode(u);
            q = q->next;
            q->insert(v,x);
        }
        else
        {
            cout << "Old source entered.\n";
            gnode* q = ghead;
            while(q != NULL && q->source != v)
            	q = q->next;
            if(q != NULL)
            	p->insert(v,x);
            else
            {
            	char ch;
            	cout << "New destination entered.\nDo you want to add new city?(y/n): ";
            	cin >> ch;
            	if(ch == 'n')
            		return;
            	p->insert(v,x);
            }
        }
        p = ghead;
        q = NULL;
        while(p != NULL && p->source != v)
        {
            q = p;
            p = p->next;
        }
        if(p == NULL)
        {
        	cout << "";
            q->next = new gnode(v);
        }
    }
}

void Graph::add_city()
{
	string u;
	cout << "Source: ";
	getline(cin,u);
	gnode* p = ghead;
	gnode* q;
	while(p != NULL && p->source != u)
	{
		q = p;
		p = p->next;
	}
	if(p != NULL)
	{
		cout << "City already present in graph.\n";
		return;
	}
	q->next = new gnode(u);
}

void Graph::del_path()
{
    string u,v;
    cout << "Source: ";
    getline(cin,u);
    if(u == "stop")
    {
        return;
    }
    cout << "Destination: ";
    getline(cin,v);
    gnode* p = ghead;
    while(p != NULL && p->source != u)
    {
        p = p->next;
    }
    if(p == NULL)
    {
        cout << "Source not found.\n";
        return;
    }
    p->del(v);
}

void Graph::del_city()
{
    string s;
    cout << "City: ";
    getline(cin,s);
    gnode* p = ghead;
    gnode* q;
    while(p != NULL)
    {
        if(p->source != s)
        {
            p->del(s);
        }
        p = p->next;
    }
    p = ghead;
    while(p != NULL && p->source != s)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete p;
}

int Graph::posn(string s)
{
    gnode* p = ghead;
    int cnt = 0;
    while(p != NULL && p->source != s)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

void Graph::traversal()
{
    cout << "Source: ";
    string s;
    getline(cin,s);
    int visited[10];
    for(int i=0;i<10;i++)
    {
        visited[i] = 0;
    }
    DFS(s,visited);
}

void Graph::DFS(string s,int visited[])
{
    cout << s << " visited.\n";
    visited[posn(s)] = 1;
    gnode* p = ghead;
    while(p->next != NULL && p->source != s)
    {
        p = p->next;
    }
    lnode* q = p->lhead;
    while(q != NULL)
    {
        if(visited[posn(q->dest)] == 0)
        {
            DFS(q->dest,visited);
        }
        q = q->next;
    }
}

int main()
{
    Graph a;
    cout << "1. Read Graph.\n";
    cout << "2. Display Graph.\n";
    cout << "3. Add Edge.\n";
    cout << "4. Add City\n";
    cout << "5. Delete Edge.\n";
    cout << "6. Delete City.\n";
    cout << "7. DFS.\n";
    cout << "8. Exit.\n";
    int ch;
    while(1)
    {
    	cout << "Enter choice: ";
    	cin >> ch;
    	switch(ch)
    	{
    		case 1:
    			cin.ignore(1);
    			a.read();
    			break;

    		case 2:
    			a.print();
    			break;

    		case 3:
    			cin.ignore(1);
    			a.add_edge();
    			break;

    		case 4:
    			cin.ignore(1);
    			a.add_city();
    			break;

    		case 5:
    			cin.ignore(1);
    			a.del_path();
    			break;

    		case 6:
    			cin.ignore(1);
    			a.del_city();
    			break;

    		case 7:
    			cin.ignore(1);
    			a.traversal();
    			break;

    		case 8:
    			return 0;

    		default:
    			cout << "Invalid choice.\n";
    			break;
    	}
    }
}
