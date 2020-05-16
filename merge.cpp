#include<iostream>
using namespace std;
void mergesort(int*,int,int);
void merge(int*,int,int,int);
int main()
{
int a[100],n,i,j;
cout<<"size";
cin>>n;
cout<<"elements";
for(i=0;i<n;i++)
cin>>a[i];
mergesort(a,0,n-1);
cout<<"sorted";
for(i=0;i<n;i++)
cout<<" "<<a[i];

}
void mergesort(int*a,int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}
}
void merge(int*a,int low,int mid,int high)
{
int i,j,k,c[100];
i=low;k=low;j=mid+1;
while(i<=mid&&j<=high)
{
if(a[i]<a[j])
{
c[k]=a[i];
k++;i++;
}
else{c[k]=a[j];
k++;j++;}
}
while(i<=mid)
{
c[k]=a[i];
k++;i++;
}
while(j<=high)
{
c[k]=a[j];
k++;j++;
}
for(i=low;i<k;i++)
{
a[i]=c[i];
}
}
