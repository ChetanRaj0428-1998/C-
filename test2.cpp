#include<iostream>
using namespace std;
class node
{
public:
int data;
node*next;
};

class queue:public node
{public:
node*front,*rear;
queue()
{
front=NULL;
rear=NULL;
}
     void insert(); // to insert an element
      void del();  // to delete an element
      void show(); // to show the stack
};

void queue::insert()
{
int x;
node*ptr;
cout<<"enter element";
cin>>x;
ptr=new node;
ptr->data=x;
ptr->next=NULL;
if(front==NULL)
front=ptr;
else
rear->next=ptr;
rear=ptr;
}
void queue::del()
{
node*temp;
if(front==NULL)
{
cout<<"queue is empty";
}
temp=front;
front=front->next;
cout<<"deleted"<<temp->data;
delete temp;
}

void queue::show()
{node*p=front;
if(front==NULL)
{
cout<<"queue is empty";
}
while(p!=NULL)
{
cout<<p->data<<"->";
p=p->next;
}
cout<<"end";

}
int main()
{
   //clrscr();
   queue q;
   int choice;
   while(1)
   {
      cout<<"\n-----------------------------------------------------------";
      cout<<"\n\t\tQUEUE USING LINKED LIST\n\n";
      cout<<"1:INSERTION\n2:DELETION\n3:DISPLAY QUEUE\n4:EXIT";
      cout<<"\nEnter your choice(1-4): ";
      cin>>choice;
      switch(choice)
      {
       case 1:
	  q.insert();
	  break;
       case 2:
	  q.del();
	  break;
       case 3:
	  q.show();
	  break;
       case 4:
	  exit(0);
	  break;
       default:
	  cout<<"Please enter correct choice(1-4)!!";
	//  getch();
	  break;
       }
   }
   return 0;
}
 
