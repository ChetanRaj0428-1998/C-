#include<iostream>
using namespace std;
int bin[5][5],val=0,i,j,x,count=0,p=0,b[12];
int display();
int cut();
void check();
int main()
{
for(i=0;i<12;i++)
{
b[i]=0;
}

for(int i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
val=val+1;
bin[i][j]=val;
}
}
display();
for(;;)
{
cut();
}
}
int display()
{system("clear");
for(int i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
cout<<"   "<<bin[i][j]<<"\t";
}
cout<<endl<<endl;

}

}

int cut()
{
for(i=0;i<10;i++)
{
cout<<"Enter the elemnt";
cin>>x;
for(i=0;i<5;i++)
for(j=0;j<5;j++)
if(bin[i][j]==x)
{
bin[i][j]=0;

}
display();
check();
if(count==5)
{system("clear");
cout<<"                      YOU WON THE GAME !!!!! CONGRADULATIONS           ";
}
cout<<endl<<"count:"<<count;

}

}

void check()
{ 
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

