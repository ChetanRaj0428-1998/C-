#include<iostream>
using namespace std;
class bingo
                                                       {
public:
int bin[5][5],i,j,pn,num,char cross,temp,np,front,rear,que[10];
void insert();
void display();
int turn(int x);
void number();
void opponent();
void push(int x);
void pop();
bingo()
                                         {
front=-1;
rear=-1;const cross=0;
cout<<"Enter the no. of players playing the game"<<endl;
cin>>np
cout<<"Enter player no."<<endl;
cin>>pn;
void insert();
int turn(pn);
                                         }

                                                       };




void bingo::push(int x)
{
++rear;
que[rear]=x;
cout<<"pushed "<<x;
}

void bingo::pop()
{
if(front==rear)
{
cout<<"queue is empty"<<endl;
}
front++;
cout<<"popped "<<que[front];
return;
}

void bingo::insert()
{
cout<<"Enter your card elements";
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
cin>>bin[i][j];
}
}
return;
}

void bingo::display()
{
cout<<"Your Card"<<endl;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
cout<<"   "<<bin[i][j]<<"\t";
}
cout<<endl;
return;
}
}

int bingo::turn(int x)
{
for(i=0;i<25;i++)
{
for(j=1;j<=np;j++)
{
void push(i);
}
temp=pop();push(temp);
if(temp==pn)
{
void number();
void display();
}
else
{
void opponent();
void display();
}
}
}


void bingo::number()
{
cout<<"Your Turn \nChoose a number from 1-25";
cin>>num;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(a[i][k]==num)
{
a[i][k]=cross;
}
}
}
return;
}



void bingo::opponent()
{
cout<<"Player"<<temp<<"'turn \nEnter the number of opponent"<<endl;
cin>>num;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(a[i][k]==num)
{
a[i][k]=cross;
}
}
}
return;
}


int main()
{
bingo ob;
}
