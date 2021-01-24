#include<iostream>

using namespace std;
struct node
{
    int data;
    node *next;
}*front,*rear,*newptr,*np;

node *createnode(int );
void insert_node(node* );
void delete_node();
void display(node* );

int main()
{
    front=rear=NULL;
    int info;
    char ch='y';
    while(ch=='y' || ch=='Y')
    {
        cout<<"\nEnter information for node:";
        cin>>info;
        newptr=createnode(info);
        if(newptr==NULL)
            cout<<"\nCannot create new node...";
        insert_node(newptr);
        cout<<"\nThe queue is:\n";
        display(front);
        cout<<"\nWant to insert more new node:";
        cin>>ch;       
    }

    char chdel;
    cout<<"\nWant to delete elements from queue?(Y/N): ";
    cin>>chdel;
    if(chdel=='y' || chdel=='Y')
    {
        char c='y';
        while(c=='y' || c=='Y')
        {
            delete_node();
            cout<<"\nThe queue after deletion is:\n";
            display(front);
        
            cout<<"\nWant to delete more node?(Y/N):";
            cin>>c;
        }
        
    }

    return 0;
}
node *createnode(int n)
{
    np=new node;
    np->data=n;
    np->next=NULL;
    return np;
}

void insert_node(node *np)
{
    if(front==NULL)
        front=rear=np;
    else
    {
        rear->next=np;
        rear=np;
    }
} 
void delete_node()
{
    if(front==NULL)
        cout<<"\nUNDERFLOW!!";
    else
    {
        np=front;
        front=front->next;
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