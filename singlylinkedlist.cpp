#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
}*head,*ptr,*temp,*newptr,*rear;


class singlylinkedlist
{
    public:
    
    node* createnode(int value);
    void insert_beg(node *np);
    void insert_at(int pos,node *np);
    void insert_end(node *np);
    void display(node *np);
    void Delete_beg();
    void Delete_at(int pos);
    void Delete_end();
    

};
node* singlylinkedlist::createnode(int value)
{
    ptr=new node;
    ptr->data=value;
    ptr->next=NULL;
    return ptr;
}

void singlylinkedlist::insert_beg(node *np)
{
    if(head==NULL)
        head=np;
    else
    {
        temp=head;
        head=np;
        np->next=temp;
    }
    
}
void singlylinkedlist::insert_at(int pos,node *np)
{
    int i=1;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    np->next=temp->next;
    temp->next=np;
    
}
void singlylinkedlist::insert_end(node *np)
{
    np->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=np;
 
}

void singlylinkedlist::display(node *np)
{
    while(np!=NULL)
    {
        cout<<np->data<<"->";
        np=np->next;
    }
    cout<<"\n";
}
void singlylinkedlist::Delete_beg()
{
    if(head==NULL)
        cout<<"UNDERFLOW!!!";
    else
    {
        temp=head;
        head=head->next;
        delete temp;
    }
    
}
void singlylinkedlist::Delete_at(int pos)
{
    struct node *np;
    temp=head;
    int i=1;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    np=temp->next;
    temp->next=np->next;
    delete np;

}
void singlylinkedlist::Delete_end()
{
    struct node *prevnode;
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)
        head=0;
    else
    {
        prevnode->next=NULL;
    }
    delete temp;
    
    
}


int main()
{
    head=NULL;
    int loc;
    int choice;
    singlylinkedlist obj;
    int info;
    char ch='y';
    char chdel='y';
    while(ch=='y' || ch=='Y')
    {
        cout<<"Enter info for node:\n";
        cin>>info;
        cout<<"creating the node...\n";
        newptr=obj.createnode(info);
        if(newptr!=NULL)
        {
            cout<<"node created successfully....\n";
        }
        else
        {
            cout<<"Cannot create node...\n";
        }
   
        
        cout<<"This node can be inserted at the following position.\n";
        cout<<"1.Insert at beginning...press 1:\n";
        cout<<"2.Insert at specified position:..press 2:\n";
        cout<<"3.Insert at end..press 3:\n";
        cout<<"Enter your choice...";
        cin>>choice;
        switch (choice)
        {
            case 1:
                obj.insert_beg(newptr);
                break;
                
            case 2:
                cout<<"Insert position..\n";
                cin>>loc;
               obj.insert_at(loc,newptr);
               break;
            case 3:
                obj.insert_end(newptr);
                break;
            default:
                cout<<"invalid choice.";
                break;
        }
        cout<<"The list is..\n";
        obj.display(head);
        cout<<"Want to insert more node...??";
        cin>>ch;
    }
    while(chdel=='y' || chdel=='Y')
    {
        cout<<"This node can be deleted at the following position.\n";
        cout<<"1.Delete at beginning...press 1:\n";
        cout<<"2.Delete at specified position:..press 2:\n";
        cout<<"3.Delete at end..press 3:\n";
        cout<<"Enter your choice...";
        cin>>choice;
        
        switch (choice)
        {
        case 1:
            obj.Delete_beg();
            break;
        case 2:
            cout<<"Insert position..\n";
            cin>>loc;
            obj.Delete_at(loc);
            break;
        case 3:
            obj.Delete_end();
            break;
        default:
            cout<<"invalid choice.";
            break;
        }
        cout<<"The list is..\n";
        obj.display(head);

        cout<<"Want to delete once more...??";
        cin>>chdel;
    }

return 0;

}

