//07
/*First line: n, a number (1<=n<=10).
Output:
Each line will contain a list of space-separated digits where
● The list contains n digits.
● The digits in the list are 0-4 (inclusive)
● The odd indexed digit in the list is an odd digit
● The even indexed digit in the list is an even digit
The lists will be printed in sorted order. Example: {0, 1, 0} before {0, 1, 2}.*/

#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n,int index)
{
    if(index==n)
    {
        for(int i=0;i<n;i++)
        {
           if(i==n-1)
           {
            cout<<arr[i];
           }
           else{
            cout<<arr[i]<<" ";
           }
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<5;i++)
    {
        if(i%2!=index%2) continue;
        arr[index]=i;
        print(arr,n,index+1);
        
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    print(arr,n,0);
}