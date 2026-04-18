///Evaluate Prefix expreesion
#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<cstring>
#include <cstdlib>
#include <cmath>
int EvaluatePrefix(queue<string>& q);
string Calculate(string x,string op_rator,string y);

string Calculate(string x,string op_rator,string y)
{
    int result,digit1,digit2;
    digit1=atoi(y.c_str());
    digit2=atoi(x.c_str());
    switch(op_rator[0])
    {
        case '+': result=digit1+digit2;break;
        case '*':  result=digit1*digit2;break;
        case '-': result=digit2-digit1; break;
        case '/': result=digit2/digit1;break;
        case '^': result=pow(digit1,digit2);break;
    }
    char s[100];
    itoa(result,s,10);
    x=s;
    return x;
}
int EvaluatePrefix(queue<string>& q)
{
    cout<<" 1";
    stack<string> stak;
    string result,y,x,op;
    while(q.empty()==false)
    {
        x=q.front();
        q.pop();
        if(isdigit(x[0]))
        {
            result=x;
            y=stak.top();
            while(isdigit(y[0]))
            {
                stak.pop();
                if(stak.size()>0)
                 {
                    op=stak.top();
                   stak.pop();
                 }
                result=Calculate(y,op,result);
                if(stak.size()>0)
                  y=stak.top();
                else
                  break;
            }
            stak.push(result);
        }
        else
        {
            stak.push(x);
        }

    }
    cout<<" Result Prefix = "<<stak.top()<<endl;
    int answer=atoi(result.c_str());
    return answer;

}
