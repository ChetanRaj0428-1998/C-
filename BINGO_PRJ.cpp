#include<iostream>
#include<cstdlib>
using namespace std;
class queue
{
public:
int a,x,front,rear,/*que[10]*/np,pn,i,j,bin[5][5],num,val,b[12],count; 
double que[10];//const int que[10]={1,2,3,4,5,6,7,8,9,10};
queue()
{
count=0;
for(i=0;i<12;i++)
{
b[i]=0;
}

for(i=0;i<2;i++)
{
front=-1;
rear=-1;
val=0;
}
}
};
class operations:public queue
{
public:
int push( double que[],int numb);
int pop(double que[]);
void turn();
void player();
void disp();
void number(double bin[][5],int limit);
//void opponent();
int insert(double bin[][5],int limit);
int display( double bin[][5],int limit);
int papa(const double que[]);
void check(double bin[][5]);
operations()//Players Module
{
cout<<"Enter the no. of players playing the game \n";
cin>>np;
cout<<"Enter Player ID:";
cin>>pn;
for(i=1;i<=np;i++)
{
push(que,i);
}
} 
};
int operations::push( double que[],int numb)//queue
{
++rear;
 que[rear]=numb;
papa(que);
return 0;
}

int operations::pop(double que[])//queue
{
++front;
return que[front];
}
int operations::papa(const double que[])
{
return 0;
}
void operations::turn()
{
a=pop(que);
push(que,a);
if(a==pn)
{
cout<<"Your turn\n";
//number();
}
else 
{
cout<<"opponents turn\n"<<"player"<<a<<"'s turn"; 
//number();
}
return;
}



void operations:: number(double bin[][5],int limit)//marking module
{
cin>>num;

for(int i=0;i<5;i++)
for(int j=0;j<5;j++)
if(bin[i][j]==num)
{
bin[i][j]=0;
check(bin);
}
display(bin,5);
check(bin);
}




int operations::insert(double bin[][5],int limit)//elements in card
{
for(i=0;i<limit;i++)
{
for(int j=0;j<limit;j++)
{
++val;
bin[i][j]=val;
}
}
}


int operations::display(double bin[][5],int limit)//display module
{
system("clear");
cout<<"Your Card"<<endl;
for(i=0;i<limit;i++)
{
for(j=0;j<limit;j++)
{
cout<<"   "<<bin[i][j]<<"\t";
}
cout<<endl<<endl;
}
if(count==5)
{
system("clear");
cout<<"                                                   ";
cout<<"                                                 ";
cout<<"                                                    ";
cout<<"CONGRADULATIONS!!!!YOU'VE WON THE GAME                   ";
cout<<"                                                                          ";
cout<<"                                                            ";
cout<<"                                                    ";
exit(0);
}
}

void operations::check(double bin[][5])
{
//cout<<"count"<<count;
if(b[0]==0&&bin[0][0]==0&&bin[0][1]==0&&bin[0][2]==0&&bin[0][3]==0&&bin[0][4]==0)
{

++count;
b[0]=1;
}
 if(b[1]==0&&bin[1][0]==0&&bin[1][1]==0&&bin[1][2]==0&&bin[1][3]==0&&bin[1][4]==0)
{

++count;
b[1]=1;
}
 if(b[2]==0&&bin[2][0]==0&&bin[2][1]==0&&bin[2][2]==0&&bin[2][3]==0&&bin[2][4]==0)
{

++count;
b[2]=1;
}
 if(b[3]==0&&bin[3][0]==0&&bin[3][1]==0&&bin[3][2]==0&&bin[3][3]==0&&bin[3][4]==0)
{

++count;
b[3]=1;
}
 if(b[4]==0&&bin[4][0]==0&&bin[4][1]==0&&bin[4][2]==0&&bin[4][3]==0&&bin[4][4]==0)
{

++count;
b[4]=1;
}

if(b[5]==0&&bin[0][0]==0&&bin[1][0]==0&&bin[2][0]==0&&bin[3][0]==0&&bin[4][0]==0)
{
++count;
b[5]=1;
}
if(b[6]==0&&bin[0][1]==0&&bin[1][1]==0&&bin[2][1]==0&&bin[3][1]==0&&bin[4][1]==0)
{
++count;
b[6]=1;
}
if(b[7]==0&&bin[0][2]==0&&bin[1][2]==0&&bin[2][2]==0&&bin[3][2]==0&&bin[4][2]==0)
{
++count;
b[7]=1;
}
if(b[8]==0&&bin[0][3]==0&&bin[1][3]==0&&bin[2][3]==0&&bin[3][3]==0&&bin[4][3]==0)
{
++count;
b[8]=1;
}
if(b[9]==0&&bin[0][4]==0&&bin[1][4]==0&&bin[2][4]==0&&bin[3][4]==0&&bin[4][4]==0)
{
++count;
b[9]=1;
}
if(b[10]==0&&bin[0][0]==0&&bin[1][1]==0&&bin[2][2]==0&&bin[3][3]==0&&bin[4][4]==0)
{
++count;
b[10]=1;
}

if(b[11]==0&&bin[0][4]==0&&bin[1][3]==0&&bin[2][2]==0&&bin[3][1]==0&&bin[4][0]==0)
{
++count;
b[11]=1;
}


return ;

}



int main()
{system("clear");
double k[5][5];
operations ob;
ob.insert(k,5);
ob.display(k,5);
for(;;)
{
ob.turn();
ob.number(k,5);
//ob.display(k,5);
//ob.check(k);
}
}

