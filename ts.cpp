#include<iostream>
using namespace std;
class queue
{
public:
int a,front,rear,que[10],np=0,i,pn;
};
class operations:public queue
{
public:
int front=-1,rear=-1;

void push(int x);
int pop();
void turn();
void player();
operations()
{
for(i=1;i<=np;i++)
{
push(i);
}
}
};

void operations::push(int x)
{
++rear;
que[rear]=x;
//cout<<"pushed "<<x;
}

int operations::pop()
{
//if(front==rear)
//{
//cout<<"queue is empty"<<endl;
//}
++front;
//cout<<"popped "<<que[front];
return que[front];
}
void operations::player()
{
while(np==0)
{
cout<<"Enter the no. of player  \n";
cin>>np;
}
cout<<endl<<"Enter player no \n ";
cin>>pn;
}
void operations::turn()
{
//for(int j=0;j<25;j++)

//cout<<"Players:";
for(i=1;i<=np;i++)
{
a=pop();
cout<<a;
break;
push(a);
}
if(a==pn)
{
cout<<"Your turn\n";
operations();
}
else 
cout<<"opponents turn\n";
operations(); 
}
int main()
{
operations ob;
for(int i=0;i<7;i++)
{
ob.player();
ob.turn();
}
}
