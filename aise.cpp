#include<iostream>
using namespace std;
class samp
{
public:
int x,bin[5][5],i,j,count;
samp()
{
count=0;
}
void matrix()
{
cout<<"Enter the elements"<<endl;
for(i=0;i<5;i++)
for(j=0;j<5;j++)
cin>>bin[i][j];
}
void display()
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
cout<<"count:"<<count
}
}

void cut()
{
cout<<"Enter the elemnt";
cin>>x;
for(int i=0;i<5;i++)
for(int j=0;j<5;j++)
if(bin[i][j]==x)
{
bin[i][j]=0;
}

}
void check()
{
for(i=0,j=0;i<5;j++)
if(bin[i][j]==0)
{
++count;
}
}
};



int main()
{
samp o;
o.matrix();
o.display();
for(;;)
{
o.cut();
o.display();
}
}

