// Write down an algorithm (pseudocode) for printing all the words: (i) consisting of letters {A, B, C}, (ii) of
// length K where K>5, (iii) having more than four "A".
#include<bits/stdc++.h>
using namespace std;
void result(string s,char ans[],int index,int k)
{
      if(index==k)
      {    
           int count=0;
           for(int i=0;i<k;i++)
           {
               if(ans[i]=='A') count++;
           }
           if(count>=4){
            for(int i=0;i<k;i++)
            {
                cout<<ans[i];
            }
            cout<<endl;
           }
           return;
      }
      for(int i=0;i<s.size();i++)
      {
            ans[index] =s[i];
            result(s,ans,index+1,k);
      }
}
int main()
{
    string s;
    s="ABC";
    string ans;
    char arr[5];
    result(s,arr,0,5);
}