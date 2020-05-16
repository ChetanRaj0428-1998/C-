#include<iostream>
#include<cstdlib>
using namespace std;
class queue
{public:
int front,rear,que[10],i,np=0,pn;
queue()
{
front=-1;
rear=-1;
}
};
class operations:public queue
{
public:
void push(int x);
int pop();
void display();
void dis();
void player();
operations()
{
cout<<"Enter the no. of player  \n";
cin>>np;
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
if(front==rear)
{
cout<<"queue is empty"<<endl;
}
front++;
//cout<<"popped "<<que[front];
return que[front];
}

void operations::display()
{
if(front==rear)
{
cout<<"queue is empty"<<endl;
}
for(int i=front+1;i<=rear;i++)
cout<<que[i]<<" ";
}

void operations::dis()
{
int a=pop();
cout<<"value of a="<<a;
push(a);
if(a==pn)
cout<<"Player"<<a<<"Turn";
else
cout<<"Opponents"<<a<<"Turn";

}

void operations::player()
{

cout<<endl<<"Enter player no \n ";
cin>>pn;
}

main()
{
     int ch;
     operations qu;
     while(1)
        {
             cout <<"\n1.push  2.pop  3.display 4.exit 5.tur 6.player\nEnter ur choice";                           
             cin >> ch;
             switch(ch)
              {
               case 1:  cout <<"enter the element";
                       cin >> ch;
                        qu.push(ch);
                        break;
               case 2:  qu.pop();  break;
               case 3:  qu.display();break;
               case 4:  exit(0);
               case 5: qu.dis();break;
               case 6: qu.player();break;
}
         }
return (0);
}
