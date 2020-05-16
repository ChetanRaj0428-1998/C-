#include<stdio.h>
void main()
{
int time,at[10],bt[10],small,n,i,sum_bt=0,sum_turnaround=0,sum_wait=0;
printf("SJF\n");
printf("Enter the no. of processes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the arrival and burst time of process %d",i+1);
scanf("%d%d",&at[i],&bt[i]);
sum_bt+=bt[i];
}
bt[9]=9999;
printf("\n process\t arrival time\tburst time\t waiting time\tturnaround time\n");
for(time=0;time<sum_bt;)
{
small=9;
for(i=0;i<n;i++)
{
if(at[i]<=time&&bt[i]>0&&bt[i]<bt[small])
small=i;
}

if(small==9)
{
time++;
continue;
}

printf("%d\t|%d\t\t|%d\t\t|%d\t\t|%d\n",small+1,at[small],bt[small],time-at[small],time+bt[small]-at[small]);
sum_turnaround+=time+bt[small]-at[small];
sum_wait+=time-at[small];
time+=bt[small];
bt[small]=0;
}
printf("\ntwt=%f",sum_wait*1.0);
printf("\nawt=%f",sum_wait*1.0/n);
printf("\nttat=%f",sum_turnaround*1.0);
printf("\natat=%f",sum_turnaround*1.0/n);
}

