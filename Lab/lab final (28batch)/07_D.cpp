//07
#include<bits/stdc++.h>
using namespace std;
void permute(int arr[],int n,int index)
{
    if(index>=n)
    {
        for(int i=0;i<n;i++)
        {
            if(i==n-1) cout<<arr[i];
            else cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<5;i++)
    {
        if(index%2!=i%2) continue;
        arr[index]=i;
        permute(arr,n,index+1);
    }
}





int main()
{
    int n;
    cin>>n;
    int arr[n];
    permute(arr,n,0);

}