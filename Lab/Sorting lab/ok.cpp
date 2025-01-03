#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x;
    cin>>x;
    char count[26]={0};
    for(int i=0;i<x.size();i++)
    {
        count[x[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
       if(count[i]!=0)
       {
        for(int j=0;j<count[i];j++)
        {
            cout<<char(i+'a');
        }
       }
      
    }
}