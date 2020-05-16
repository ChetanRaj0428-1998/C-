#include<iostream>
using namespace std;
class A
{
public:
void meth1();
void meth2();
};
void A::meth1()
{
cout<<"hwello meth 2";
 meth2();
}
void A::meth2()
{
cout<<"hello meth 1";
return;
}

int main()
{
A ob;
ob.meth1();
}




