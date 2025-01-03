//07
//07
//07
//07
#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
  if(c=='^') return 3;
  else if(c=='*'||c=='/') return 2;
  else if(c=='+'||c=='-') return 1;
  else return -1;
}

void infix(string x)
{
     stack<char>p;
     string res="";
     for(int i=0;i<x.size();i++)
     {
         char a=x[i];
         if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
         {
               res+=a;
         }
         else if(a=='(')
         {
            p.push(a);
         }
         else if(a==')')
         {
            while(p.top()!='(')
            {
                res+=p.top();
                p.pop();
            }
            p.pop();
         }
         else{
            if(!p.empty()&& prec(a)<=prec(p.top()))
            {
                res+=p.top();
                p.pop();

            }
            p.push(a);
         }
     }
     while(!p.empty())
     {
        res+=p.top();
        p.pop();
     }
     cout<<res<<endl;
}

int main()
{
    string x;
    cin>>x;
    infix(x);
}