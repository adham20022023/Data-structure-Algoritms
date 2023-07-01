#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool par(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    else if (open == '{' && close == '}')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else
        return false;
}
bool balanced(string exp)
{
    stack<char> stk;
    for (int x = 0; x < exp.size(); x++) // for loop character by character of string user Enter
    {
        if (exp[x] == '(' || exp[x] == '{' || exp[x] == '[')
        { // push first open bracket in the stack
            stk.push(exp[x]);
        }
        if (exp[x] == ')' || exp[x] == '}' || exp[x] == ']')
        {
            if (stk.empty()) // that mean string start with close without open which not right
                return false;
            else if (par(stk.top(), exp[x]) == false)
                // check if close and open from the same type
                // for example: [],not right ->[}
                return false;
            stk.pop(); // pop any element from stack to add new element
        }
    }
    // if user enter for example { nothing else
    // then { will rename their
    // and this make experassion not balance
    if (stk.empty())
        return true;
    else
        return false;
}
int main()
{
    cout << "Enter String to check if it Balance Or Not: ";
    string input;
    cin >> input;
    if (balanced(input))
        cout << "Experession is balanced\n";
    else
        cout << "Experession Not Balanced \n";
    return 0;
}
