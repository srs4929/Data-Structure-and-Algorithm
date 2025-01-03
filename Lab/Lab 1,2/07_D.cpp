//07
#include<bits/stdc++.h>
using namespace std;
void eva(string x)
{
    stack<int>p;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]>='0'&&x[i]<='9')
        {
            int c=x[i]-'0';
            p.push(c);
        }
        else if(x[i]=='+')
       {
           int op2=p.top();
           p.pop();
           int op1=p.top();
           p.pop();
           p.push(op1+op2);

       }
       else if(x[i]=='-')
       {
           int op2=p.top();
           p.pop();
           int op1=p.top();
           p.pop();
           p.push(op1-op2);
       }
       else if(x[i]=='*')
       {
           int op2=p.top();
           p.pop();
           int op1=p.top();
           p.pop();
           p.push(op1*op2);
       }
       else  
       {
        int op2=p.top();
           p.pop();
           int op1=p.top();
           p.pop();
           p.push(op1/op2);
       }
    }
    cout<<p.top()<<endl;
}
int main()
{
    string x;
    cin>>x;
    eva(x);
}