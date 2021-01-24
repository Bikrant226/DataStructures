#include<iostream>

using namespace std;

int pop(int [],int& );
int push(int [],int&,int);
void display(int [],int );

const int size=50;

int main()
{
    int stack[size],item,top=-1,res;
    char ch='y';
    while(ch=='y' || ch=='Y')
    {
        cout<<"Insert item:\n";
        cin>>item;
        res=push(stack,top,item);
        if(res==-1)
            cout<<"OVERFLOW!!!\n";
        cout<<"The stack is:\n";
        display(stack,top);
        cout<<"Want to insert more element??\n";
        cin>>ch;
    }
    cout<<"Deletion begins..\n";
    ch='y';
    while(ch=='y' || ch=='Y')
    {
        res=pop(stack,top);
        if(res==-1)
            cout<<"UNDEFLOW!!!\n";
        else
        {
            cout<<"Item deleted is:"<<res;
            cout<<"\nThe stack now is:\n";
            display(stack,top);
        }
        cout<<"Want to delete more nodes??\n";
        cin>>ch;
        
    }

}
int push(int stack[],int &top,int element)
{
    if(top==size-1)
        return -1;
    else
    {
        top++;
        stack[top]=element;
    }
    return 0;
    
}
void display(int stack[],int top)
{
    if(top==-1)
        return;
    cout<<stack[top]<<"<-- top of the stack"<<endl;
    for(int i=top-1;i>=0;i--)
        cout<<stack[i]<<endl;
}

int pop(int stack[],int &top)
{
    int  ret;
    if(top==-1)
        return -1;
    else
    {
        ret=stack[top];
        top--;
    }
    return ret;
    
}