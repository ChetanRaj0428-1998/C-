#include<iostream>
using namespace std;
class FCFS
{
int i,j,n,at[10],bt[10],ct[10],tat[10],wt[10],rq[10],gc[10],min,min_index;
public:
void scheduling();
void CT();
void display();
void sort();
void TAT_WT();
FCFS()
{
gc[0]=0;//gantt chart starts from 0
cout<<"Enter the no. of processes:";
cin>>n;
for(i=0;i<n;i++)
{

cout<<"PROCESS "<<i+1<<endl;
cout<<"arrival time:";
cin>>at[i];
cout<<"burst time:";
cin>>bt[i];
}
}
};

void FCFS::sort()
{
int temp;
for(i=0;i<n-1;i++)
{
min=at[i];
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

}


void FCFS::scheduling()
{
gc[0]=gc[0]+at[0];
for(i=0;i<n;i++)
{
gc[i+1]=bt[i]+gc[i];
}
}

void FCFS::CT()
{
for(i=0;i<n;i++)
{
ct[i]=gc[i+1];
}
}

void FCFS:: TAT_WT()
{
for(i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
}
}

void FCFS:: display()
{
 cout<<"ARRIVAL TIME	"<<"BURST TIME	"<<"COMPLETION TIME	"<<"TURN AROUND TIME	  "<<"WAITING TIME"<<endl;
for(i=0;i<n;i++)
{
 cout<<"  "<<at[i]<<"	"<<bt[i]<<"   "<<ct[i]<<"   "<<tat[i]<<"   "<<wt[i]<<endl;
}
}

int main()
{
FCFS ob;
ob.sort();
ob.scheduling();
ob.CT();
ob.display();
}
