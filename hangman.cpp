#include<iostream>
using namespace std ;
class BINGO
{public:
int a[5][5],i,j,n=5;

void insert()
{
cout<<"Enter the elements of our card"<<endl;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cin>>a[i][j];
}
}


void display()
{
cout<<"Numbers in your card";
for(i=0;i<n;i++)
for(j=0;j<n;j++)
cout<<endl<<a[i][j];
}

};

void main()
{
BINGO b;
b.insert();
b.display();
}
