/*In this problem, you will be given an postfix expression where each operand is a digit.
Evaluate it. In addition to the usual arithmetic operators as +, -, *, /, there will be two
new unary operators as described below. In mathematics, a unary operation is an
operation with only one operand.
#, where A# = A + 1
$, where A$ = A - 1
In case of divided by zero, increase the divisor by two.*/
#include<bits/stdc++.h>
using namespace std;
void eva(string x)
{
    stack<int>s;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]>='0'&&x[i]<='9')
        {
             int p=x[i]-'0';
             s.push(p);
        }
        else
        {
            if(x[i]=='+')
            {
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                int result=op1+op2;
                s.push(result);
            }
            else if(x[i]=='-')
            {
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                int result=op1-op2;
                s.push(result);
            }
            else if(x[i]=='*')
            {
                 int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                int result=op1*op2;
                s.push(result);
            }
            else if(x[i]=='/')
            {
                 int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                if(op2==0) op2=op2+2;
                int result=op1/op2;
                s.push(result);
            }
            else if(x[i]=='#')
            {
                int x=s.top();
                s.pop();
                int result=x+1;
                s.push(result);
            }
            else
            {
                int x=s.top();
                s.pop();
                int result=x-1;
                s.push(result);
            }

            
        }
    }
    cout<<s.top()<<endl;
}
int main()
{
    string x;
    cin>>x;
    eva(x);
}