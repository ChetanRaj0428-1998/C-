#include<iostream>
using namespace std;
int part(int[],int,int);
int quick(int[],int,int);
int main()
{
int a[100],n,i;
cout<<"size";
cin>>n;
cout<<"elements";
for(i=0;i<n;i++)
cin>>a[i];
quick(a,0,n-1);
for(i=0;i<n;i++)
cout<<" "<<a[i];
}

int quick(int a[],int l,int u)
{
int j;
if(l<u)
{
j=part(a,l,u);
quick(a,l,j-1);
quick(a,j+1,u);
}
}
int part(int a[],int l,int u)
{
int i,j,v,temp;
v=a[l];
i=l;
j=u+1;
do
{
do
i++;
while(a[i]<v&&i<=u;);
do
j--;
while(v<a[j]);
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}while(i<j);
a[l]=a[j];
a[j]=v;
return(j);
}

