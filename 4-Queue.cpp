#include <iostream>
#define size 100
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
    return rear == size - 1;
}
void Q::enque(int num)
{
    if (is_full())
    cout << "Sorry Enque Is Full !!" << endl;
    else{
    if (front == -1)
        front = 0;
    rear++;
    item[rear] = num;
    }
}
bool Q::is_empty()
{
    return front == -1;
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
        front++;
    }
}
void Q::display()
{
if(!is_empty())
    for (int i = front; i <= rear; i++)
    {

            cout << item[i] << "\t";
    }
    cout << endl;
}
int main()
{
    Q q;
    q.enque(1);  // front=0; //rear=0
    q.enque(2);  // front=0  //rear=1
    q.enque(3);
    q.display(); // display from 0 to 1
    q.deque();
    q.deque();
    q.deque();
    q.display();
    return 0;
}
