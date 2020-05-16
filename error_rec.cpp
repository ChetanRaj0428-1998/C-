#include<iostream>
#include<cstdlib>
using namespace std;
class queue
{
public:
int a,x,t,front,rear,que[10],np,pn,i,j,bin[5][5],num,temp,b[2],val;
const int 
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
void push(int num);
int pop();
void turn();
void player();
void disp();
void number();
//void opponent();
void insert();
void display();
int cheat(int x,int y);
int check();
operations()//Players Module
{
cout<<"Enter the no. of players playing the game \n";
cin>>np;
for(i=1;i<=np;i++)
{
push(i);
}
}

};
void operations::push(int num)//queue
{
++rear;
que[rear]=num;

}

int operations::pop()//queue
{
if(front==rear)
{
cout<<"queue is empty"<<endl;
}
front++;
return que[front];
}



void operations::turn()
{
int const a=pop();
cout<<"Popped value"<<a;
push(a);
if(a==pn)
{
cout<<"Your turn\n";
number();
}
else 
{
cout<<"opponents turn\n"<<"player"<<a<<"'s turn"; 
number();
}
}


void operations:: number()//marking module
{
cin>>num;
for(int i=0;i<5;i++)
for(int j=0;j<5;j++)
if(bin[i][j]==num)
{
//cheat(a,num);

 bin[i][j]=0;
}
}


void operations::insert()//elements in card
{
for(i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
++val;
bin[i][j]=val;
}
}


void operations::display()//display module
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

int main()
{
operations ob;
ob.player();
ob.insert();
ob.display();
for(int i=0;i<25;i++)
{

ob.turn();
ob.display();
}
}
