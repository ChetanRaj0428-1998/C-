#include<iostream>
#include<cstdlib>
using namespace std;
class node
{public:
int data;
node*next;
};
class stack:public node
{public:
node*top;
stack()
{
top=NULL;
}
void push();
void pop();
void view();
};

void stack::push()
{
int x;
node*ptr;
cout<<"element";
cin>>x;
ptr=new node;
ptr->data=x;
ptr->next=NULL;
if(top!=NULL)
ptr->next=top;//increment
top=ptr;//ptr address in top
}

void stack::pop()
{
node*temp;
if(top==NULL)
{
cout<<"stack is empty";
}
temp=top;
top=top->next;//decrement
cout<<"deleted"<<temp->data;
delete temp;
}

void stack::view()
{
node*m=top;

if(top==NULL)
{
cout<<"stack is empty";
}
else
{
while(m!=NULL)
{
cout<<m->data<<"->";
m=m->next;
}
cout<<"NULL";
}
}
int main()
{
    stack s;
    int choice;
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\tSTACK USING LINKED LIST\n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY STACK\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.view();
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"\nPlease enter correct choice(1-4)!!";
                break;
        }
    }
    return 0;
}



