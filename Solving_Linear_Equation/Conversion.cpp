///Convert a fully parentesized infix expression to postfix
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
void infixToPostFix()
{
    queue<string> q;
    string input;
    cout<<"Enter infix Expression: ";
    cin.ignore();
    getline(cin,input);
    char* tokens;
    tokens=strtok(&input[0]," ");
    while(tokens!=NULL)
    {
        q.push(tokens);
        tokens=strtok(NULL," ");
    }
    string front;
    stack<string> stak;
    cout<<"\nEquivslent Postfix: ";
    while(q.empty()==false)
    {
        front=q.front();
        q.pop();
        if(isdigit(front[0]))
           cout<<front<<" ";
        else if(front==")")
        {
          if(!stak.empty())
            {
                while(stak.top()!="(")
            {
                cout<<stak.top()<<" ";
                 stak.pop();
                 if(stak.empty())
                     break;
            }
            if(!stak.empty())
             stak.pop();

           if(!stak.empty())
            {
                while(stak.top()!="(")
              {
                cout<<stak.top()<<" ";
                 stak.pop();
              }
            }
          }
        }
        else
        {
            stak.push(front);
        }

    }

}
