//07
#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int k,int index)
{
    if(index==k)
    {
        for(int i=0;i<k;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=4;i>=0;i--)
    {
        if((index+1)%2!=i%2) continue;
        arr[index]=i;
        print(arr,k,index+1);
    }
}
int main()
{
    int k;
    cin>>k;
    int arr[k+1];
    print(arr,k,0);

}