#include<iostream>
#include<fstream>
#include"Postfix.cpp"
#include"Infix.cpp"
#include"Prefix.cpp"
#include"Conversion.cpp"
#include"SolvingEquation.cpp"
using namespace std;
queue<double> qOutput;
queue<string> qInput;

void DisplayMenu();
void inputExpression();
void writeFile();
void readFile();
void printRecords();
void InsertInQ(string copy,double result);
void TrigonometricFunctions();
void logarithm();

void DisplayMenu()
{
    cout<<"\nMenu\n";
    cout<<"[1] Evaluate infix ,postfix,or prefix expression\n";
    cout<<"[2] Solve linear equation\n";
    cout<<"[3] Infix to Postfix\n";
    cout<<"[4] Find value of sin cos tan\n";
    cout<<"[5] Find log10 and ln\n";
    cout<<"[6] View last five opertaion\n";
    cout<<"[7] EXIT\n";
    cout<<"\nEnter your choice: ";

}
void inputExpression()
{
    double result;
    queue<string> q;
    cout<<"Enter Expression: ";
    cin.ignore();
    string input,front,copy;
    getline(cin,input);
    copy=input;
    char* tokens;
    tokens=strtok(&input[0]," ");
    while(tokens!=NULL)
    {
        q.push(tokens);
        tokens=strtok(NULL," ");
    }
    front=q.front();
     if(isOperator(copy[0]))
        {
            result=EvaluatePrefix(q);
        }
     else if(isOperator(copy[copy.length()-1]))
     {
        result=EvaluatePostfix(q);
     }
     else if(isdigit(copy[0]))
       {
           result=EvaluateInfix(q);
          cout<<"Result Infix = "<<result<<endl;
       }
     else
       cout<<"Syntax Error!\n";
     InsertInQ(copy,result);
}
void InsertInQ(string copy,double result)
{
     if(qOutput.size()>=5)
          {
              qInput.pop();
              qInput.push(copy);
              qOutput.pop();
              qOutput.push(result);
          }
       else
       {
            qInput.push(copy);
            qOutput.push(result);
       }
       writeFile();
}
void writeFile()
{
    ofstream writeInputs("RecordInput.txt");
    ofstream writeOutputs("RecordOutput.txt");
      if(writeInputs.fail()||writeOutputs.fail())
       cout<<"Error Opening File!"<<endl;
      string inputs;
    double outputs=qOutput.front();
    while(qInput.empty()==false)
    {
        inputs=qInput.front();
        qInput.pop();
        writeInputs<<inputs<<"\n";
    }
    while(qOutput.empty()==false)
    {
        outputs=qOutput.front();
        qOutput.pop();
        writeOutputs<<outputs<<" ";
    }
    writeInputs.close();
    writeOutputs.close();
    readFile();

}
void readFile()
{
    ifstream readInput("RecordInput.txt");
    ifstream readOutput("RecordOutput.txt");
    if(readInput.fail()||readOutput.fail())
       cout<<"Error Opening File!"<<endl;
    string inputs;
    double outputs;
    readOutput>>outputs;
    while(readInput.peek()!=EOF)
       {
           getline(readInput,inputs);
            qInput.push(inputs);
       }
      while(readOutput)
       {
        qOutput.push(outputs);
        readOutput>>outputs;
      }
    readInput.close();
    readOutput.close();

}
void printRecords()
{
    string inputs;
    double outputs;
    int i=1;
     while(qInput.empty()==false&&qOutput.empty()==false)
    {
        inputs=qInput.front();
        qInput.pop();
        outputs=qOutput.front();
        qOutput.pop();
        cout<<"Input "<<i<<" :"<<inputs<<endl;
        cout<<"Output : "<<outputs<<endl;
        i++;
    }
    readFile();
}

int main()
{
    readFile();
   int choice;
   double result;
   string input;
    while(1)
    {
        DisplayMenu();
        cin>>choice;

        switch(choice)
      {
        case 1:inputExpression();break;
        case 2:
                  cout<<"\nEnter linear equation: ";
                  cin.ignore();
                  getline(cin,input);
                result=SolveLinearEquation(input);
                InsertInQ(input,result);
                break;
        case 4: TrigonometricFunctions();
               break;
        case 5: logarithm();
               break;
        case 3: infixToPostFix();break;
        case 6: printRecords();
              break;
        case 7: return 1;
      }
    }
    return 0;
}
void TrigonometricFunctions()
{
    double angle,a;
    cout<<"Angle = ";
    cin>>angle;
    a=(angle/180.0)*2*acos(0.0);

    cout<<"cos("<<angle<<") = "<<cos(a)<<endl;
    cout<<"sin("<<angle<<") = "<<sin(a)<<endl;
    cout<<"tan("<<angle<<") = "<<tan(a)<<endl;

}
void logarithm()
{
    double arg;
    cout<<"Argument of log = ";
    cin>>arg;

    cout<<"log("<<arg<<") = "<<log(arg)<<endl;
    cout<<"log10("<<arg<<") = "<<log10(arg)<<endl;

}
