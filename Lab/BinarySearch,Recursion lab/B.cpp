//07
//07
//07
//07
/*Problem B
You will be given the marks of students in a particular course. Output the id of the
students according to the ascending order of their marks. In case of same marks, the
smaller id value will be printed.
Input:
First line: n, a number. (1<=n<=10^5)
Next n lines: two integers id mark (0<=id, mark <=2147483647), the id and mark of a
student.
Output:
n lines, each containing the id of a student according to the order defined above.
input:
3 
1 5 
2 3
3 4
output:
2 3 1*/


#include<bits/stdc++.h>
using namespace std;

void mergesort(pair<int,int>arr[],int s,int e)
{
    int mid=(s+e)/2;
    int n1=(mid-s+1);
    int n2=(e-mid);
    pair<int,int>first[n1],last[n2];
    int l=s;
    for(int i=0;i<n1;i++)
   {
        first[i]=arr[l++];
   }
    for(int i=0;i<n2;i++)
   {
        last[i]=arr[l++];
   }
   
   int k=s;
   int i=0;
   int j=0;
   while(i<n1&&j<n2)
   {
       if (first[i].second < last[j].second || 
           (first[i].second == last[j].second && first[i].first < last[j].first)) {
            arr[k++] = first[i++];
        } else {
            arr[k++] = last[j++];
        }
   }
   while(i<n1)
   {
       arr[k++]=first[i++];
   }
   while(j<n2)
   {
     arr[k++]=last[j++];
   }
}
void merge(pair<int,int>arr[],int s,int e)
{
     int mid=(s+e)/2;
     if(s>=e) return;
     merge(arr,s,mid);
     merge(arr,mid+1,e);
     mergesort(arr,s,e);
}
int main()
{
    int n;
    cin>>n;
    pair<int,int>arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    merge(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].first<<endl;
    }
}