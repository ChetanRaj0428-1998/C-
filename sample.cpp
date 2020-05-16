#include<iostream>
using namespace std;
class sample
{public:
int a,*b;
void fun();
};
void sample::fun()
{sample *x;
x=new sample;
cout<<"enter the value to be stored in the node";
cin>>x->a;
cout<<"the address of next node stored in pointer"<<endl;
x->b=NULL;
cout<<"the value is "<< x->a << "and the address of next the node"<< x->b;
}
main()
{sample o;
o.fun();
}

