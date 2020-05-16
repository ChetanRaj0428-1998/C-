#include<iostream>
using namespace std;
class bingo
                                                       {
public:
int bin[5][5],i,j,pn,num,temp,np,front,rear,que[10],cross;
/*void insert();
void display();
int turn(int x);
void number();
void opponent();
void push(int x);
void pop();*/
bingo()
                                         {
front=-1;
rear=-1;const int cross=0;
cout<<"Enter the no. of players playing the game"<<endl;
cin>>np;
cout<<"Enter player no."<<endl;
cin>>pn;
                                         }

                                                       




int push(int x)
{
++rear;
que[rear]=x;
cout<<"pushed "<<x;
return x;
}

int pop()
{
if(front==rear)
{
cout<<"queue is empty"<<endl;
}
front++;
cout<<"popped "<<que[front];
}

void insert()
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

void display()
{
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

int turn()
{

cout<<"working";
void number();
}



void number()
{
cout<<"Your Turn \nChoose a number from 1-25";
cin>>num;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(bin[i][j]==num)
{
bin[i][j]=cross;
}
}
}
return;
}



void opponent()
{
cout<<"Player"<<temp<<"'turn \nEnter the number of opponent"<<endl;
cin>>num;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(bin[i][j]==num)
{
bin[i][j]=cross;
}
}
}
return;
}

};
int main()
{
bingo ob;
ob.insert();

ob.turn();
for(int i=0;i<5;i++)
ob.number();
}
