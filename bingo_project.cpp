#include<iostream>
#include<cstdlib>
using namespace std;
class queue
{
public:
int a,x,front,rear,/*que[10]*/np,pn,i,j,bin[5][5],num,val; 
double que[10];//const int que[10]={1,2,3,4,5,6,7,8,9,10};
queue()
{

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
int display(const double bin[][5],int limit);
int papa(const double que[]);
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
}

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


int operations::display(const double bin[][5],int limit)//display module
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
ob.display(k,5);

}
}

