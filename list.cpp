#include<iostream>
using namespace std;
class list
{
public:
int a[100],n,i,l;
list()
{
 l=0;
cout<<"enter array size";
cin>>n;
}
void insert();
void delet();
void view();
};

void list::insert()
{
cout<<"enter the elements"<<endl;
for(i=0;i<n;i++)
{
cin>>a[i];
++l;
}
cout<<"elements inserted"<<endl;
}

void list::delet()
{int x;
cout<<"enter the element to delete";
cin>>x;
for(i=0;i<n;i++)
{
if(x==a[i])
{
for(int j=i;j<n;j++)
{
a[j]=a[j+1];
}
--l;
}
}
}

void list::view()
{
cout<<"elements are"<<endl;
for(i=0;i<l;i++)
cout<<a[i];
}

main()
{
list o;
int c;
while(1)
{
cout<<"\n 1.insert \n 2.delete \n3.view"<<endl;
cin>>c;
switch(c)
{
case 1:o.insert();break;
case 2:o.delet();break;
case 3:o.view();break;
}
}
}
