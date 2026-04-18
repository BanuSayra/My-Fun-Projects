///Evaluating Postfix Expression using stack and Queue
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
bool isOperator(char c);
int EvaluatePostfix(queue<string>& tokensQ);
int Calculate(int digit1,int digit2,char op_rator);

bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
      return true;
    else
      return false;
}
int Calculate(int digit1,int digit2,char op_rator)
{
    int result;
    switch(op_rator)
    {
        case '+': result=digit1+digit2;break;
        case '*':  result=digit1*digit2;break;
        case '-': result=digit2-digit1; break;
        case '/': result=digit2/digit1;break;
        case '^': result=pow(digit1,digit2);break;
    }
    return result;
}

int EvaluatePostfix(queue<string>& q)
{
    stack<int> numberStack;
    string str;
    int digit,i,digit1,digit2,result;
    while(q.empty()==false)
    {
        str=q.front();

        if(isdigit(str[0])==true)
          {
              digit=atoi(str.c_str());
              numberStack.push(digit);
          }
        else if(isOperator(str[0])==true)
        {
            digit1=numberStack.top();
            numberStack.pop();
            digit2=numberStack.top();
            numberStack.pop();
            result=Calculate(digit1,digit2,str[0]);
            numberStack.push(result);

        }
        q.pop();

    }
    result=numberStack.top();
    numberStack.pop();
    if(numberStack.empty())
     cout<<"Result Postfix = "<<result<<endl;
    else
     cout<<"Expression Not in Postfix form! "<<endl<<endl;
     return result;

}

