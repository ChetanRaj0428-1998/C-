#include<iostream>
#include<cstdlib>
using namespace std;
class stack
{
public:
int i,top,stk[10],n,x;
stack()
{
top=-1;
}
void push();
void pop();
void display();
void update();
void sort();
void reverse();
void search(int z);
void check();
};
void stack::reverse()
{
if(top<0)
{
cout<<"stack is empty";
}
cout<<"stack in reverse order";
for(int i=0;i>=top;i++)
cout<<stk[i]<<" ";
}

void stack::push()
{
char c;
if(top>=9)
{
cout<<"stack is empty";
}
else
cout<<"Do you want to push more that one elements in one go?......press y for yes n for no";
cin>>c;
if(c=='y')
{
cout<<"enter the elements";
for(i=top;top<=9;++top)
{
cin>>stk[top];
}
}
else
{
cout<<"enter the element:";
cin>>x;
++top;
stk[top]=x;
cout<<"element pushed";
}
}


void stack::pop()
{
if(top<0)
{
cout<<"stack is empty";
}
cout<<"popped "<<stk[--top];
}

void stack::display()
{
if(top<0)
{
cout<<"stack is empty";
return;
}
cout<<"elements in the stack are:"<<endl;
for(int i=top;i>=0;i--)
{
cout<<stk[i]<<" ";
}
for(int i=0;i>=top;i++)
cout<<stk[i]<<" ";

}

void stack::update()
{
int value,y;
if(top<0)
{
cout<<"stack is empty"<<endl;
goto l;
}
cout<<"enter the postion in stack to update"<<endl;
cin>>y;
if(y<=top+1&&y!=0)
{
cout<<"enter the new value"<<endl;
cin>>value;
stk[--y]=value;
cout<<"value updated"<<endl;
}
else l:cout<<"position does not exist";
}
void stack::search(int z)
       {
int i,t;
if(top<0)
      {
goto l;
      }
cout<<"searching.....";
for(i=0;i<=top+1;++i)
   {
if(z==stk[i])
{t=stk[i];
cout<<"your value is in the stack at "<<i<<"th inedx position";   
}


}
if(t!=z) l:cout<<"value not in stack";
       }

void stack::sort()
{
int temp;
char c;
if(top<0)
{
cout<<"stack is empty"<<endl;
}
else
{
cout<<"sorting....";
for(int i=1;i<=top;i++)
{
for(int j=0;j<top-1;j++)
{
if(stk[j]>stk[j+1])
{
temp=stk[i];
stk[i]=stk[j];
stk[j]=temp;
}
} 
}
cout<<" sorted stack values are:"<<endl;
for(int i=0;i<=top;i++)
{
cout<<stk[i]<<" ";
}
cout<<endl<<"do u wish to save this stack order....type y/n";
cin>>c;
if(c=='y')
{
{
for(int i=top;i<=0;i--)
{
cout<<stk[i]<<" ";
}
}
}
else
{
cout<<"sorted stack is not original stack";
}
}
}

void stack::check()
{
if(top<0)
{
cout<<"stack is empty"<<endl;
}
else
{
cout<<endl<<"the top most value in the stack and the value that will pop:"<<endl;
cout<<stk[top]<<endl;
cout<<"the value in the stack inserted at first and last to be popped:"<<endl;
cout<<stk[0];
}
}



main()
{
     int ch,a[100];
     stack st;
     while(1)
        {
             cout<<"\n1.push  2.pop  3.display 4.update 5.search 6.sort 7.check 8.reverse 9.exit\nEnter ur choice:";
             cin >> ch;
             switch(ch)
              {
               case 1:  st.push();
                        break;
               case 2:  st.pop();  break;
               case 3:  st.display();break;
               case 4:  st.update();break;
               case 5: if(st.top<0){cout<<"stack is empty";break;}
                        cout<<"enter the element to search"<<endl;
                        cin>>ch;
                        st.search(ch);
                        break;
               case 6:  st.sort();break;
               case 7:  st.check();break;
               case 8: st.reverse();break;
               case 9:  exit(0);
  
}
cout<<endl;
         }
return (0);
}
  
