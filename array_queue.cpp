#include<iostream>
#include<stdlib.h>

using namespace std;

int removenode(int []);
int insertnode(int [],int );
void displaynode(int [],int ,int );

const int size=50;
int queue[size],front=-1,rear=-1;
int main()
{
    int item,res;
    char ch='y';
    while(ch=='y' || ch=='Y')
    {
        cout<<"\nEnter item for insertion:";
        cin>>item;
        res=insertnode(queue,item);
        if(res==-1)
            cout<<"\nCannot create node...";
        
        cout<<"\nThe queue is:\n";
        displaynode(queue,front,rear);
    
        cout<<"\nWant to insert more items?(Y/N):";
        cin>>ch;
    }
    
    cout<<"\nDeletion begins...";
    ch='y';
    while(ch=='y' || ch=='Y')
    {
        res=removenode(queue);
        if(res==-1)
            cout<<"UNDERFLOW!!";
        else
        {
            cout<<"\nElement deleted is:"<<res<<endl;
            cout<<"\nNow the queue is:\n";
            displaynode(queue,front,rear);
        }
        cout<<"\nWant to delete more elements??";
        cin>>ch;
    }
    return 0;
}

int insertnode(int queue[],int info)
{
    if(rear==size-1)
        return -1;
    else if(rear==-1)
    {
        front=rear=0;
        queue[rear]=info;
    }
    return 0;
}

int removenode(int queue[])
{
    int ret;
    if(front==-1)
        return -1;
    else
    {
        ret=queue[front];
        if(front==rear)
            front=rear=-1;
        else
            front++;
    }
    return ret;
    
}

void displaynode(int queue[],int front,int rear)
{
    if(front==-1)
        return;
    for(int i=front;i<rear;i++)
        {
            cout<<queue[i]<<"<--\t";
        }
    cout<<queue[rear]<<endl;
}