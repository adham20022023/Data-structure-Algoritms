#include<iostream>
using namespace std;
class linked_list
{
    private:
    struct node
    {
        int data;
        node *next;
        node *prev;
        node()
        {
            next=nullptr;
            prev=nullptr;
        }
    };
    node *head=NULL;
    public:
    void insert_at_first(int val);
    void insert_at_last(int val);
    void insert_at_position(int pos,int val);
    void delete_at_first();
    void delete_at_last();
    void delete_at_pos(int pos);
    void delete_value(int val);
    void display();
    void display_reverse();
    ~linked_list()
    {
        node* temp = head;
		while (head != nullptr){
			head = head->next;
			delete temp;
			temp = head;
    }
    }
};
void linked_list::insert_at_first(int val)
{
    node *newnode=new node;
    newnode->data=val;
    if(head==nullptr)
    {
        head=newnode;
    }
        else
        {
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
}
void linked_list::insert_at_last(int val)
{
    node *newnode=new node;
    newnode->data=val;
    if(head==nullptr)
        head=newnode;
    else
    {
        node *temp=head;
        while(temp->next!=nullptr)
            temp=temp->next;
            temp->next=newnode;
            newnode->prev=temp;
    }

}
void linked_list::insert_at_position(int pos,int val)
{
    node *newnode=new node;
    newnode->data=val;
    if(head==NULL)
    {
        head=newnode;
        return ;
    }
    if(pos==0)
    {
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
            return ;
    }
    node *temp=head;
    for(int x=0;x<pos;x++)
    {
        if(temp==nullptr)
            break;
        else
        temp=temp->next;
    }
        if(temp==nullptr)
        {
            this->insert_at_last(val);
            return;
        }
        newnode->prev=temp->prev;
        temp->prev->next=newnode;
        newnode->next=temp;
        temp->prev=newnode;
}
void linked_list::delete_at_first()
{
    if(head==nullptr)
    {
        return ;
    }
    node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
}
void linked_list::delete_at_last()
{
    if(head==nullptr)
    {
        return ;
    }
    if(head->next==nullptr)
    {
        head=NULL;
        return ;
    }

    node *temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->prev->next=nullptr;
    delete temp;
}
void linked_list::delete_at_pos(int pos)
{
    if(head==nullptr)
    {
        return;
    }
    if(pos==0)
    {
        node *temp=head;
        head=temp->next;
        if(head)//if there is one element in linked list
        head->prev=nullptr;
        delete temp;
        return ;
    }
    else
    {
        node *temp=head;
    for(int i=0;i<pos&&temp!=nullptr;i++)
    {
        temp=temp->next;
    }
    if(temp==nullptr)
    {
        delete_at_last();
        return ;
    }
    temp->prev->next=temp->next;
        if(temp->next)
    temp->next->prev=temp->prev;
    delete temp;
}
}
void linked_list::delete_value(int val)
{
    if(head==nullptr)
        return;
    if(head->data!=val)
    {
        if(head->next==nullptr)
        {
        node *temp=head;
        head=nullptr;
        delete temp;
        return;
        }
        else
        {
            node *temp=head;
            head=head->next;
            head->prev=nullptr;
            delete temp;

        }

    }
}
void linked_list::display()
{
    if(head==NULL)
       {
           cout<<"NO Elements In list"<<endl;
           return ;
       }
    else
    {
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    }
}
void linked_list::display_reverse()
{
        if(head==NULL)
       {
           cout<<"NO Elements In list"<<endl;
           return ;
       }
       else
       {
    node *temp=head;
        while(temp->next!=NULL)
    {
        temp=temp->next;
    }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
       }
}
int main ()
{
    size_t cho=0;
    linked_list obj;
    int num, pos;
    while(cho!=9)
    {
        cout<<"1-Insert element at the first position"<<endl;
        cout<<"2-Insert element at the last position"<<endl;
        cout<<"3-Insert Element at Position you choose"<<endl;
        cout<<"4-Delete element at the first position"<<endl;
        cout<<"5-Delete element at the last position"<<endl;
        cout<<"6-Delete Element at Position you choose"<<endl;
        cout<<"7-Display elements at the list"<<endl;
        cout<<"8-Display elements In Reverse Way"<<endl;
        cout<<"9-Exit From Programm"<<endl;
        cout<<"Enter What You Want To Do: ";
        cin>>cho;
                system("cls");
        switch(cho)
        {
        case 1:
            cout<<"Enter Number: ";
            cin>>num;
            obj.insert_at_first(num);
            break;
        case 2:
            cout<<"Enter Number: ";
            cin>>num;
            obj.insert_at_last(num);
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
            obj.delete_at_pos(pos);
            break;
        case 7:
             obj.display();
             break;
        case 8:
            obj.display_reverse();
            break;
        case 12:
            cout<<"Enter Number You Want To Delete :";
            cin>>num;
            obj.delete_value(num);
            break;
        case 9:
        break;
        default:
                cout<<"What Have You choosen :)"<<endl;

        }
    }
    return 0;
}
