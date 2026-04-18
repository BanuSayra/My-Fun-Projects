///Solve Linear Equation
#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<cstring>
#include <cstdlib>
#include <cmath>
#include"Infix.cpp"
bool is_Operator(char c);
double SolveLinearEquation(string input);
double SolveLinearEquation(string input)
{
    queue<string> q;
    string front,oprator;
    char variable=' ';
    char* tokens;
    tokens=strtok(&input[0]," ");
    while(tokens!=NULL)
    {
        q.push(tokens);
        tokens=strtok(NULL," ");//storing LHS of equation
        if (tokens[0]=='=')
           break;
    }
    tokens=strtok(NULL," ");
    if(tokens[0]=='+')
    {
        q.push("-");
    }
    else if(tokens[0]=='-')
    {
        q.push("+");
    }
    else   //  Must b a term
    {
      q.push("-");
      q.push(tokens);
    }

    tokens=strtok(NULL," ");

    while(tokens!=NULL)
    {
        if(tokens[0]=='+')
          q.push("-");
        else if(tokens[0]=='-')
        {
            q.push("+");
        }
        else
         q.push(tokens);

        tokens=strtok(NULL," ");
    }
    queue<string> varq,consq;
    while(q.empty()==false)
    {
        front=q.front();
        if(is_Operator(front[0]))
        {
            oprator=front;
        }
        else if(isdigit(front[front.length()-1]))//term is a constant
        {
            if(oprator!=" ")
               consq.push(oprator);
            consq.push(front);

        }
        else
        {
            if(oprator!=" ")
              varq.push(oprator);
            if(variable==' ')
              variable = front[front.length()-1];
            if(front.length()==1)
               front="1";
            else
               front=front.erase(front.length()-1,1);
            varq.push(front);

        }
        q.pop();
    }
    if(varq.front()=="+")
      varq.pop();
    if(consq.front()=="+")
      consq.pop();
     int sumOfconstant = EvaluateInfix(consq);
     sumOfconstant*=-1;/// change of sign as the constant is moved to RHS
     int sumOfvariable = EvaluateInfix(varq);
     double result = (double)sumOfconstant/(double)sumOfvariable;
     cout<<"\nValue of "<<variable<<" = "<<result<<endl;
    return result;
}
bool is_Operator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
      return true;
    else
      return false;
}
