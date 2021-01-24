#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
}*top,*newptr,*np,*temp;

node *create_node(int );
void push(node* );
void pop();
void display(node* );

int main()
{
    top=NULL;
    int info;
    char ch='y';
    while(ch=='y' || ch=='Y')
    {
        cout<<"\nEnter information for new node:";
        cin>>info;
        newptr=create_node(info);
        if(newptr==NULL)
            cout<<"\nCannot create node...";
        push(newptr);
        cout<<"\nThe stack is:\n";
        display(top);
        cout<<"\nWant to insert more nodes?(Y/N)";
        cin>>ch;
    }

    do
    {
        cout<<"\nThe stack is:\n";
        display(top);
        cout<<"\nWant to pop an element?(Y/N):";
        cin>>ch;
        if(ch=='y' || ch=='Y')
            pop();
    } while (ch=='y' || ch=='Y');
    
    return 0;    
}

node *create_node(int n)
{
    np=new node;
    np->data=n;
    np->next=NULL;
    return np;
}

void push(node *np)
{
    if(top==NULL)
        top=np;
    else
    {
        temp=top;
        top=np;
        np->next=temp;
    }
    
}

void pop()
{
    if(top==NULL)
        cout<<"\nUNDERFLOW!!";
    else
    {
        np=top;
        top=top->next;
        delete np;
    }
    
}
void display(node *np)
{
    while(np!=NULL)
    {
        cout<<np->data<<"-->";
        np=np->next;
    }
    cout<<"\n";
}