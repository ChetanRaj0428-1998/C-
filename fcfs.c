#include<stdio.h>

void getdata();
void wait();
void turnaround();
void display();
int i,n,at[10],bt[10],wt[10],tat[10];
float twt=0,ttat=0;

void main()
{
//system("clear");
printf("FCFS\n");
getdata();
wait();
turnaround();
display();
}

void getdata()
{
printf("Enter the no. of processes\n");
scanf("%d",&n);
printf("Enter the burst and arrival time of the processes\n");
for(i=0;i<n;i++)
{
scanf("%d%d",&bt[i],&at[i]);
}
}

void wait()
{
int s=0;
wt[0]=0;
for(i=0;i<n;i++)
{
s=s+bt[i-1];
wt[i]=bt[i]-at[i];
twt=wt[i]+twt;
}
}

void turnaround()
{
tat[-1]=0;
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
ttat=ttat+tat[i];
}
}


void display()
{
printf("PROCESS\t|BURST TIME\t|ARRIVAL TIME\t|WAITING TIME\t|TURNAROUND TIME\n");
for(i=0;i<n;i++)
{
printf("%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\n",i+1,bt[i],at[i],wt[i],tat[i]);
}
printf("TOTAL WAITING TIME=%f",twt);
printf("AVG. TOTAL WAITING TIME=%f",twt/n);
printf("TOTAL TURNAROUND TIME=%f",ttat);
printf("AVG. TURNAROUND TIME=%f",ttat/n);
}
