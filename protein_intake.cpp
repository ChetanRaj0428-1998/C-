#include<iostream>
using namespace std;
class protein
{
public:
int a[100],sum,n;

protein()
{
cout<<"How many protein values are you going to enter:";
cin>>n;
}
void insert()
{
cout<<"enter the protein values"<<endl;
for(int i=0;i<n;i++)
cin>>a[i];
}
int add()
{sum=0;
for(int i=0;i<n;i++)
{
sum=sum+a[i];
}
cout<<"Your total protein intake for the day is:";
cout<<sum<<endl;
}

};

main()
{
protein o;
o.insert();
o.add();
}
