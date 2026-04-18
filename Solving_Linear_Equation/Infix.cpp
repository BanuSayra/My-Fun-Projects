//Evaluating Arithmatic Expression using stack and Queue
#ifndef INFIX_CPP
#define INFIX_CPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
int EvaluateInfix(queue<string>& tokensQ);
int Prec(char op);
void repeatOps(char refOp);

stack<int> valStack;
stack<string> opStack;

int Prec(char op)
{
    if(op=='$')
      return 0;
    else if(op=='+'||op=='-')
     return 2;
    else if(op=='*'||op=='/'||op=='%')
     return 3;
    else if (op=='^')
     return 4;
    else if (op=='<'||op=='>')
     return 1;
    else
    return -1;
}
int EvaluateInfix(queue<string>& tokensQ)
{
    string tok = tokensQ.front();
    if(tok=="-")
     {
         tokensQ.pop();
         tok=tokensQ.front();
         int num=atoi(tok.c_str());  //Negating the number
         num*=-1;
         valStack.push(num);
         tokensQ.pop();
     }
    while(tokensQ.empty()==false)
    {
        tok=tokensQ.front();
        tokensQ.pop();
        if(isdigit(tok[0]))
         {
             int x=atoi(tok.c_str());
             valStack.push(x);
         }
         else
         {
             if(opStack.empty())
             {
                 opStack.push(tok);
             }
             else
              {
                  repeatOps(tok[0]);
                  opStack.push(tok);
              }
         }
    }
    if(valStack.size()>1)
       repeatOps('$');
    int result=valStack.top();
    valStack.pop();
    return result;
}
void doOp()
{
    int x,y;
    string item;
    int result;
    x=valStack.top();
    valStack.pop();
    y=valStack.top();
    valStack.pop();
    item=opStack.top();
    opStack.pop();
    char op_rator=item[0];
    switch(op_rator)
    {
        case '+': result=y+x;break;
        case '-': result=y-x;break;
        case '/': result=y/x;break;
        case '*': result=y*x;break;
        case '%': result=y%x;break;
        case '^': result=pow(y,x);break;
        case '<': result=x<=y;break;
        case '>': result=x>=y;break;
    }
    valStack.push(result);
}
void repeatOps(char refOp)
{
    string topItem;
    topItem=opStack.top();
    bool lowerPrec=(Prec(refOp)<=Prec(topItem[0]));
    while(valStack.size()>1&&lowerPrec)
    {
        doOp();
        if(opStack.empty()) break;
        topItem=opStack.top();
        lowerPrec=(Prec(refOp)<=Prec(topItem[0]));
    }
}
#endif


