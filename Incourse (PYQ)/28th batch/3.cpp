// Write down an algorithm (pseudocode) for printing all the words: (i) consisting of letters {A, B, C}, (ii) of
// length K where K>5, (iii) having more than four "A".

#include<bits/stdc++.h>
using namespace std;

void recu(string x,int k,char res[],int index)
{

    if(index>=k)
    {   
        int count=0;
        for(int i=0;i<k;i++)
        {
             if(res[i]=='A') count++;
        }
        if(count>4)
        {
            for(int i=0;i<k;i++)
            {
                cout<<res[i];
            }
            cout<<endl;
        }
        return ;
    }
    for(int i=0;i<x.size();i++)
    {
        res[index]=x[i];
        recu(x,k,res,index+1);
    }
}




int main()
{
    string x="ABC";
    int k;
    cin>>k;
    char res[k];
    recu(x,k,res,0);
}