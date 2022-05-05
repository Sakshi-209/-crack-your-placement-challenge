#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
if(m==0||n==0)
{
cout<<"0"<<endl;
}
sort(arr,arr+n);
if(n<m)
{
cout<<"-1"<<endl;
}
int min=INT_MAX;
for(int i=0;i+m-1<n;i++)
{
int ans=arr[i+m-1]-arr[i];
if(ans<min)
{
min=ans;
}
}
cout<<min<<endl;
}
