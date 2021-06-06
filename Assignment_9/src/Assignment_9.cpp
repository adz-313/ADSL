//============================================================================
// Name        : Assignment_9.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

class node
{
    int data;
    node* next;
public:
    node(int x)
    {
        data = x;
        next = NULL;
    }
    friend class SLL;
};

class SLL
{
    node* head;
public:
    SLL()
    {
        head = NULL;
    }
    void create();
    void display();
    void add(int);
    void remove();
    int size();
    void intersection(SLL,SLL);
    void unio(SLL,SLL);
    void diff(SLL,SLL);
    void subset(SLL);
};

void SLL::create()
{
    char arr[5];
    int x;
    node* p;
    while(1)
    {
        cout << "Enter data: ";
        cin.getline(arr,5);
        if(strcmp(arr,"stop") == 0)
        {
            return;
        }
        x = atoi(arr);
        if(head == NULL)
        {
            head = new node(x);
            p = head;
        }
        else
        {
            int flag = 0;
            node* q = head;
            while(q != NULL)
            {
                if(q->data == x)
                {
                    flag = 1;
                    break;
                }
                q = q->next;
            }
            if(flag == 1)
            {
                cout << "Repeat.\n";
            }
            else
            {
                p->next = new node(x);
                p = p->next;
            }
        }
    }
}

void SLL::display()
{
    node* p = head;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void SLL::add(int x)
{
    /*int x;
    cout << "Enter element to be added: ";
    cin >> x;*/
    node* p = head;
    if(p == NULL)
    {
        head = new node(x);
    }
    else
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = new node(x);
    }
}

void SLL::remove()
{
    int x;
    cout << "Enter element to be removed: ";
    cin >> x;
    node* p = head;
    if(p == NULL)
    {
        cout << "List empty.\n";
        return;
    }
    else
    {
        node* q = NULL;
        while(p != NULL)
        {
            if(p->data == x)
            {
                break;
            }
            q = p;
            p = p->next;
        }
        if(q == NULL)
        {
            head = head->next;
            delete p;
            return;
        }
        if(p == NULL)
        {
            cout << "Element not found.\n";
            return;
        }
        q->next = p->next;
        delete p;
    }
}

int SLL::size()
{
    node* p = head;
    int cnt = 0;
    while(p != NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

void SLL::unio(SLL a,SLL b)
{
    node* p = a.head;
    node* q = b.head;
    node* r = head;
    int flag = 0;
    while(p != NULL)
    {
        add(p->data);
        p = p->next;
    }
    while(q != NULL)
    {
        node* p = a.head;
        while(p != NULL)
        {
            if(q->data == p->data)
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
                p = p->next;
            }
        }
        if(flag == 1)
        {
            add(q->data);
            flag = 0;
        }
        q = q->next;
    }
}

void SLL::intersection(SLL a,SLL b)
{
    node* p = a.head;
    node* q = b.head;
    int flag = 0;
    while(q != NULL){
        node* p = a.head;
        while(p != NULL){
            if(q->data == p->data){
                flag = 1;
                break;
            }
            else{
                flag = 0;
                p = p->next;
            }
        }
        if(flag == 1){
            add(q->data);
            flag = 0;
        }
        q = q->next;
    }
}

void SLL::diff(SLL a,SLL b)
{
    node* p = a.head;
    node* r = head;
    while(p != NULL)
    {
        node* q = b.head;
        int flag = 0;
        while(q != NULL)
        {
            if(q->data == p->data)
            {
                flag = 1;
                break;
            }
            q = q->next;
        }
        if(flag == 0)
        {
            add(p->data);
        }
        p = p->next;
    }
}

void SLL::subset(SLL a)
{
    node* q = a.head;
    while(q != NULL)
    {
        node* p = head;
        int flag = 0;
        while(p != NULL)
        {
            if(p->data == q->data)
            {
                flag = 1;
                break;
            }
            p = p->next;
        }
        if(flag == 0)
        {
            cout << "Not a subset.\n";
            return;
        }
        q = q->next;
    }
    cout << "Subset";
}

int main()
{
    SLL a,b,c;
    a.create();
    //a.display();
    //a.add();
    a.display();
    b.create();
    b.display();
    a.subset(b);
    c.display();
}
