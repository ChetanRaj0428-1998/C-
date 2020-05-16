#include<iostream>
using namespace std;
class poly
{
public:
int a[100],b[100],c[100],x,i;
poly()
{
cout<<"enter the highest coefficient of x"<<endl;
cin>>x;
}
void coff_a()
{
cout<<"1ST POLYNOIMIAL"<<endl;
for(int i=x-1;i>=0;i--)
{
cout<<"enter the coefficient"<<i<<"th power";
cin>>a[i];
}
}

void coff_b()
{cout<<"2ND POLYNOIMIAL"<<endl;
for(int i=x-1;i>=0;i--)
{
cout<<"enter the coefficient"<<i<<"th power";
cin>>b[i];
}
}
void view_a()
{cout<<"your polynomial"<<endl;
cout<<"X^"<<x<<"+";
for(int i=x-1;i>=1;i--)
{
cout<<a[i]<<"X^"<<i<<"+";
}
cout<<a[0];
}

void view_b()
{cout<<"your polynomial"<<endl;
cout<<"X^"<<x<<"+";
for(int i=x-1;i>=1;i--)
{
cout<<b[i]<<"X^"<<i<<"+";
}
cout<<b[0];
}


void add()
{
for(int i=x-1;i>=0;i--)
{
c[i]=a[i]+b[i];
}
cout<<"sum of two polynomials"<<endl;
cout<<"2"<<"X^"<<x;
for(int i=x-1;i>=1;i--)
{
cout<<"+"<<c[i]<<"X^"<<i;
}
cout<<"+"<<a[0]+b[0];
}


void sub()
{
for(int i=x-1;i>=0;i--)
{
c[i]=a[i]-b[i];
}
cout<<"difference of two polynomials"<<endl;
cout<<"0"<<"X^"<<x;
for(int i=x-1;i>=1;i--)
{
cout<<"+"<<c[i]<<"X^"<<i;
}
cout<<"+"<<a[0]-b[0];
}



 char pol()
{
{
for(int m=3;m>=0;m--)
cout<<endl;
}
return('-');
}
};

main()
{
poly y;
int c;
y.coff_a();
y.coff_b();
while(1)
{
cout<<y.pol()<<"------OPERATION-----\n1.VIEW 1st polynomial\n 2.VIEW 2nd polynomial \n3.Add the two polynomials\n4.Subtract the two polynoimials \n5.EXIT \nenter choice"<<endl;
cin>>c;
switch(c)
{
case 1:y.view_a();break;
case 2:y.view_b();break;
case 3:y.add();break;
case 4:y.sub();break;
case 5: exit(0);break;
}
}
}
