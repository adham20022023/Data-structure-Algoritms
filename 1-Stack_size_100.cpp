#include <iostream>
#include<string>
//#define max_size 100
//LIFO last in first out
using std::cin;
using std::cout;
using std::endl;
using std::string;
class stack
{
private:
    // we make it static to have access from anywhere in the full code
    // in a word we can say we make it pupblic and constant data member of class
    // we can say obj.max_size; in the main function and main will have access to it
    static const int max_size = 200;
    int item[max_size]; // stack size
    int top;

public:
    // we need 5 function
    stack() // set value for top when we create object
    {
        top = -1;
    }
    //*********************************************
    bool is_empty() // check if stack is empty
    {
        return top==-1;//this mean no element pushed in the stack
    }
    void pop()
    {
        if (is_empty())
        {
            cout << "Stack Is UnderFlow" << endl;
            cout<<"**************************"<<endl;
        }
        else
        {
            top--; // just pop element from stack
        }
    }
    int return_pop()
    {
        if (is_empty())
        {
            cout << "Stack Is UnderFlow" << endl;
        }
        else
        {
            int item = this->item[top]; // save value of element which we pop from stack
            top--;
            return item; // return value of poped element
        }
    }
    //**********************************************
    bool is_full() // check if stack if full
    {
        return (top == max_size - 1);//'-1' as we know top array start from zero so from 0 to 99 mean 100 element
    }
    void push(int item)
    {
        if (is_full()) // push elements if stack not full
        {
            cout << "Stack Is OverFlow" << endl;
        }
        else
        {
            top++;
            this->item[top] = item;
            // will return element which we push in the stack
        }
    }
    int return_push(int item)
    {
        if (stack::is_full()) // push elements if stack not full
        {
            cout << "Stack Is OverFlow" << endl;
        }
        else
        {
            top++;
            this->item[top] = item;
            return this->item[top]; // will return element which we push in the stack
        }
    }
    int peek_fun()//get the last element added in the stack
    {
        return this->item[top];
    }
    //-------------------------
    void print_all_elements() // will print all element which still in the stack
    {
        cout << "All Elements Now are " << endl;
        for (int x = 0; x <= top; x++)
        {
            cout << item[x] << " ";
        }
        cout << endl;
    }
};
int main()
{

    return 0;
}
