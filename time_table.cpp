#include<iostream>
using namespace std;
class TT
{public:
TT()
{
cout<<"Enter the day to check what classes you have:"<<endl;
}
};
main()
{
TT o;
int a;
while(1)
{
cout<<endl<<"1.MONDAY 2.TUESDAY 3.WEDNESDAY 4.THURSDAY 5.FRIDAY 6 SATURDAY 7.QUIT"<<endl<<"enter the option"<<endl;
cin>>a;
switch(a)
{
case 1:cout<<"Monday:\nCLASSES:\n1.ES \n2.DM \n3.BE(LAB) \n4.LST \n5.DS";break;
case 2:cout<<"Tuesday:\nCLASSES:\n1.DS(LAB) \n2.M-III \n3.BE \n4.LST \n5.SPORTS";break;
case 3:cout<<"Wednesday:\nCLASSES: \n1.DS \n2.LST \n3.EE(LAB) \n4.BE  \n5.ES ";break;
case 4:cout<<"Thursaday:\nCLASSES:\n1.M-III(for 2hrs) \n2.DS \n3.BE \n4.DM(for 2hrs)";break;
case 5:cout<<"Friday:\nCLASSES:\n1.LST \n2.DM \n3.DS \n4.ES \n5.m-III \n6.BE";break;
case 6:cout<<"Saturday:\nCLASSES:\n1.DS(LAB) \n2.CRT";break;
case 7:exit(0);
default:cout<<"Neeee.....Sunday kuda scollage neku kavala(-_-)";
}
}

}
