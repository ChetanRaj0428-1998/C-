#include<iostream>
using namespace std;
class postfix
{
public:
char a[100],stack[100],temp[10];
int result,top,n;
postfix()
{
top=-1;
}
void convert();
int push(int);
int pop();
void display();
void read();
};

void postfix::read()
{
cout<<"enter the the size"<<endl;
cin>>n;
cout<<"enter the postfix expression"<<endl;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
}
void postfix::convert()
{
cout<<"converting";
for(int i=0;i<n;i++)
{
if(a[i]==0||1||2||3||4||5||6||7||8||9)
{
push(a[i]);
return ;
}
else 
{
int a1,b1;
a1=pop();
b1=pop();
switch(a[i])
{
case '*':push(a1+b1);break;
case '+':push(a1*b1);break;
case '/':if(a1>b1){push(a1-b1);}else{push(b1-a1);};break;
case '-':if(a1>b1){push(a1/b1);}else{push(b1/a1);};break;
default:cout<<"unknown operator";
}
}
}
return;
}

int postfix::push(int x)
{
int r;
r=x;
++top;
stack[top]=r;
}
int postfix::pop()
{
--top;
result=stack[top];
return (result);
}

void postfix::display()
{
cout<<"result"<<result;
}

main()
{
postfix p;
p.read();
p.convert();
p.display();
}


