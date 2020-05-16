#include<iostream>
#include<cstdlib>
using namespace std;
class queue
{
public:
int a,x,t,front,rear,que[10],np,i,pn,j,bin[5][5],num,temp,b[2],val;
queue()
{
for(i=0;i<2;i++)
{
b[i]=0;
//cout<<b[i];
}
front=-1;
rear=-1;
val=0;
}
};
class operations:public queue
{
public:
void push(int num);
int pop();
void turn();
void player();
void disp();
void number();
void opponent();
void insert();
void display();
int cheat(int x,int y);
int check();
operations()
{
np=0;
cout<<"Enter the no. of players playing the game \n";
cin>>np;
for(i=1;i<=np;i++)
{
push(i);
}
}
};

void operations::push(int num)
{
++rear;
que[rear]=num;
//cout<<"pushed "<<num;
}

int operations::pop()
{
if(front==rear)
{
cout<<"queue is empty"<<endl;
}
front++;
//cout<<"popped "<<que[front];
return que[front];
}

void operations::player()
{

cout<<endl<<"Enter player no \n ";
cin>>pn;
}
void operations::turn()
{
//for(int j=0;j<25;j++)
 
//cout<<"Players:";
a=pop();
//cout<<a;
push(a);
if(a==pn)
{
cout<<"Your turn\nYour number:";
number();
}
else 
{
cout<<"Player "<<a<<"'s turn\nPlayer "<<a<<"'s number:"; 
number();
}
}


void operations:: number()
{
//cout<<" \nChoose a number from 1-25";
//cin>>num;
cin>>num;
for(int i=0;i<5;i++)
for(int j=0;j<5;j++)
if(bin[i][j]==num)
{
cheat(a,num);
bin[i][j]=0;
}
else
{
bin[i][j]=bin[i][j];
}
}



void operations::opponent()
{
cout<<" \nEnter the number of opponent"<<endl;
cin>>num;
for(i=0;i<5;i++)
for(j=0;j<5;j++)
if(bin[i][j]==num)
{
bin[i][j]=0;
}
else
{
bin[i][j]=bin[i][j];
}
}


void operations::insert()
{
for(i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
++val;
bin[i][j]=val;
}
}
}



void operations::display()
{
system("clear");
cout<<"Your Card"<<endl;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
cout<<"   "<<bin[i][j]<<"\t";
}
cout<<endl<<endl;
}
}
int operations::cheat(int x,int y)
{

b[x]=y+b[x];

}
int operations::check()
{
cout<<b[1];

}


int main()
{
operations ob;
int k;
ob.player();
ob.insert();
ob.display();
for(int i=0;i<25;i++)
{

ob.turn();
ob.display();
}

cout<<"PRESS '1 ' TO CHECK IF ANYONE CHEATED IF THE NO'S BELOW DO NOT MATCH THEN SOMEONE HAS CHEATED (>_<)"<<endl;
cin>>k;
switch(k)
{
case 1:ob.check();break;
default:cout<<"enter only 1";
}
}









