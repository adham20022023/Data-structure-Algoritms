#include <iostream>
#include <string>
#include <stack>
using namespace std;
// functions To Get Evaluation ->
float prefix_evaluation(string);
float postfix_evaluation(string);
int main()
{
    string str1;
    string str2;
    cout << "Enter Postfix To Get Evaluation:";
    cin >> str1;
    cout << "Value_is : " << postfix_evaluation(str1) << endl;
    cout << "********************************" << endl;
    cout << "Enter Prifix To get Evaluation:";
    cin >> str2;
    cout << "Value_is : " << prefix_evaluation(str2) << endl;
    cout << "**********************************" << endl;
    return 0;
}
float prefix_evaluation(string str)
{
    stack<float> stk;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (isdigit(str[i])) // push numbers
            stk.push(str[i] - '0');
        else // if it not number so it should be operation +,/,-,*
        {
            float val, op1, op2;
            op2 = stk.top(); // we use top as pop not return any value
            stk.pop();
            op1 = stk.top();
            stk.pop();
            switch (str[i])
            {
            case '+':
                val = op1 + op2;
                break;
            case '-':
                val = op1 - op2;
                break;
            case '*':
                val = op1 * op2;
                break;
            case '/':
                val = op1 / op2;
                break;
            default:
                cout << "Tell Me What Operation You use :)" << endl;
            }
            stk.push(val);
        }
    }
    return stk.top();
}
float postfix_evaluation(string str)
{
    stack<float> stk;
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
            stk.push(str[i] - '0'); // 21+
        else
        {
            float val, op1, op2;
            op2 = stk.top();
            stk.pop();
            op1 = stk.top();
            stk.pop();
            switch (str[i])
            {
            case '+':
                val = op1 + op2;
                break;
            case '-':
                val = op1 - op2;
                break;
            case '*':
                val = op1 * op2;
                break;
            case '/':
                val = op1 / op2;
                break;
            default:
                cout << "Tell Me What Operation You use :)" << endl;
            }
            stk.push(val);
        }
    }
    return stk.top();
}