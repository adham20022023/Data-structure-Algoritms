#include<iostream>
using namespace std;
class linkedlist
{
    struct node
    {
        int data;
        node *next;
    };
    node *head=NULL;
    public:
    void insert_first(int );
    void insert_last(int );
    void insert_at_position(int,int );
    bool is_empty();
    void delete_at_first();
    void delete_at_last();
    void delete_value(int);
    void delete_position(int);
    void display();
};
bool linkedlist::is_empty()
{
        return head==NULL;
}
void linkedlist::insert_first(int val)
{
    node *newnode=new node;
    newnode->data=val;
    newnode->next=NULL;
    if(is_empty())
    {
        newnode->next=newnode;
        head=newnode;

        return ;
    }
    else
    {
        node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
    }
}
void linkedlist::insert_last(int val)
{
    node *newnode=new node;
    newnode->data=val;
    newnode->next=newnode;
    if(is_empty())
    {
        head=newnode;
    }
    else
    {
        node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head;
    }
}
void linkedlist::insert_at_position(int val,int pos)
{
    node *newnode=new node;
    newnode->data=val;
    newnode->next=newnode;
    if(pos==0)
    {
        node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
        return;
    }
    else
    {
    node *temp=head;
    for(int x=1;x<pos;x++)
    {
        if(temp->next==head)
            break;
        temp=temp->next;
    }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void linkedlist::delete_at_first()
{
    if(is_empty())
        return ;
   node *temp=head;
   node *deletehead=head;
   while(temp->next!=head)
    temp=temp->next;
   head=head->next;
   temp->next=head;
   delete deletehead;
}
void linkedlist::delete_at_last()
{
    node *temp=head;
    while(temp->next->next!=head)
          {
              temp=temp->next;
          }
          delete temp->next;
          temp->next=head;
}
void linkedlist::delete_value(int val)
{
    if(is_empty())
    {
        cout<<"Linked List Is Empty"<<endl;
        return ;
    }
    node *temp=head;
    node *prev=head;
    if(temp->data==val)
    {
        head=temp->next;
        delete temp;
        return ;
    }
    while(temp != NULL&&temp->data!=val)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
        {
            cout<<"Not Found"<<endl;
        }
    else
    {
        prev->next=temp->next;
        delete temp;
    }

}
void linkedlist::delete_position(int pos)
{
    if(is_empty())
    {
        cout<<"Linked List Is Empty YOu can't remove From it"<<endl;
        return;
    }
    node *temp=head;
    if(temp->next==NULL)
    {
    head=NULL;
    delete temp;
    return;
    }
    if(pos==0)
    {
        delete_at_first();
    }
    else{
    for(int x=0;x<pos-1;x++)
    {
        if(temp->next==head)
            break;
        temp=temp->next;
    }
    if(temp->next==head)
    {
        delete_at_last();
        return ;
    }
    node *temp2=temp->next;
    temp->next=temp->next->next;
    delete temp2;

    }
}
    void linkedlist::display()
    {
        if(!is_empty())
        {
            cout<<"The List Elements :"<<endl;
        node *temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
        cout<<endl;
        cout<<"*************************"<<endl;
        }
        else
            cout<<"No Data To Display"<<endl;
            return;
    }
int main ()
{
    size_t cho=0;
    linkedlist obj;
    int num, pos;
    while(cho!=8)
    {
        cout<<"1-Insert element at the first position"<<endl;
        cout<<"2-Insert element at the last position"<<endl;
        cout<<"3-Insert Element at Position you choose"<<endl;
        cout<<"4-Delete element at the first position"<<endl;
        cout<<"5-Delete element at the last position"<<endl;
        cout<<"6-Delete Element at Position you choose"<<endl;
        cout<<"7-Display elements at the list"<<endl;
        cout<<"8-Exit From Programm"<<endl;
        cout<<"Enter What You Want To Do: ";
        cin>>cho;
        switch(cho)
        {
        case 1:
            cout<<"Enter Number: ";
            cin>>num;
            obj.insert_first(num);
            break;
        case 2:
            cout<<"Enter Number: ";
            cin>>num;
            obj.insert_last(num);
            break;
        case 3:
            cout<<"Enter Number: ";
            cin>>num;
            cout<<"Enter Position: ";
            cin>>pos;
            obj.insert_at_position(num,pos);
            break;
        case 4:
            obj.delete_at_first();
            break;
        case 5:
            obj.delete_at_last();
            break;
        case 6:
            cout<<"Enter position you want to delete: ";
            cin>>pos;
            obj.delete_position(pos);
            break;
        case 7:
             obj.display();
             break;
        case 8:
        break;
        default:
                cout<<"What Have You choosen :)"<<endl;
        }
    }
    return 0;
}
