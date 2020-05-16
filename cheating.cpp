#include<iostream>
using namespace std;
class cheating
{
public:
int a,x,z,front,rear,que[10],np,i,pn,j,bin[5][5],num,temp,b[10]={0,0,0,0,0,0,0,0,0,0};
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
void check();
cheat()
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
void cheating::push(int num)
{
++rear;
que[rear]=num;
//cout<<"pushed "<<num;
}

int cheating::pop()
{
if(front==rear)
{
cout<<"queue is empty"<<endl;
}
front++;
//cout<<"popped "<<que[front];
return que[front];
}

void cheating::player()
{

cout<<endl<<"Enter player no \n ";
cin>>pn;
}
void cheating::turn()
{
//for(int j=0;j<25;j++)
 
//cout<<"Players:";
a=pop();
//cout<<a;
push(a);
if(a==pn)
{
cout<<"Your turn\n";
number();
}
else 
{
cout<<"opponents turn\n"; 
number();
}
}


void cheating:: number()
{
//cout<<" \nChoose a number from 1-25";
//cin>>num;
cin>>num;
for(int i=0;i<5;i++)
for(int j=0;j<5;j++)
if(bin[i][j]==num)
{
cheat(pn,num);
bin[i][j]=0;
}
else
{
bin[i][j]=bin[i][j];
}
}

void cheating::insert()
{
cout<<"Enter your card elements"<<endl;
for(i=0;i<5;i++)
for(j=0;j<5;j++)
cin>>bin[i][j];
}




void cheating::display()
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
int cheating::cheat(int x,int y)
{
b[x]=y+b[x];
return 0;
}
void cheating::check()
{
for(i=1;i<=np;i++)
{
cout<<"Player"<<x<<"Code"<<b[x];
}
}


int cheating::cheat(int x,int y)
{
z=x;
b[z]=y+b[z];
return 0;
}
void cheating::check()
{
for(i=1;i<=np;i++)
{
cout<<"Player"<<i<<"Code"<<b[i];
}
}


int main()
{
cheat ob;
int k;
ob.player();
ob.insert();
ob.display();
for(int i=0;i<25;i++)
{

ob.turn();
ob.display();
}
cout<<"PRESS 'c' TO CHECK IF ANYONE CHEATED IF THE NO'S BELOW DO NOT MATCH THEN SOMEONE HAS CHEATED (>_<)"<<endl;
cin>>k;
switch(k)
{
case 1:ob.check();
}

}

