#include <iostream>
#define size 5
using namespace std;
class Q//FIFO first in last out
{
private:
    int item[size];
    int front, rear;

public:
    Q()
    {
        front = -1;
        rear = -1;
    }
    bool is_empty();
    bool is_full();
    void enque(int num);
    void deque();
    void display();
    ~Q(){};
};
bool Q::is_full()
{
    return (rear+1)%size==front;
}
void Q::enque(int num)
{
    if (is_full())
    cout << "Sorry Queue Is full element : " <<num<<"  not added"<< endl;
    else{
    if (front == -1)
        front = 0;
    rear=(rear+1)%size;
    item[rear] = num;
    }
}
bool Q::is_empty()
{
    return front == -1&&rear==-1;
}
void Q::deque()
{
    if (is_empty())
    {
        cout << "Q is Empty You Can't Deque From it" << endl;
        exit(0);
    }
    else
    {
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front=(front+1)%size;
    }
}
void Q::display()
{
if(front==-1 & rear==-1){
cout<<"underflow"<<endl;
return;
}
for(int i=front; i!=rear; i=(i+1)%size)
cout<<item[i]<<"\t";
cout<<item[rear]<<endl;
}
int main()
{
    Q q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.display();
    q.deque();
    q.deque();
    q.deque();
    q.enque(6);
    q.enque(7);
    q.enque(8);
    q.enque(9);
    q.display();
    return 0;
}
