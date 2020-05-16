#include<iostream>
using namespace std;
class sort
{
public:
int n,i,j,at[10],bt[10],temp,min,min_index;
void sort_al();
sort()
{
cout<<"enter the no. of process";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"Procecss "<<i+1;
cout<<"arrival time";
cin>>at[i];
cout<<"burst time";
cin>>bt[i];

}
cout<<"\narrival time and burst time are";
for(i=0;i<n;i++)
{
cout<<at[i]<<"  "<<bt[i]<<endl;
}
}
};

void sort::sort_al()
{
int temp;
for(i=0;i<n-1;i++)
{min=at[i];
min_index=i;
for(j=i+1;j<n;j++)
{
if(min>at[j])
{
min=at[j];
min_index=j;
}
}
temp=at[i];
at[i]=at[min_index];
at[min_index]=temp;
temp=bt[i];
bt[i]=bt[min_index];
bt[min_index]=temp;
}
cout<<"\n after sort burst time are";
for(i=0;i<n;i++)
{
cout<<bt[i]<<" ";
}
}


int main()
{
sort ob;
ob.sort_al();
}
