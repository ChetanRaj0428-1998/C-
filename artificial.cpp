#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class arti
	{public:
	int r,b[25];
	arti()
		{for(int i=0;i<25;i++)
			b[i]=0;
		}
	void random()
		{srand(time(NULL));
		r=rand()%100+1;
		r=r/4;
		check();
		}
	void check()
		{if(r==b[r-1])
			random();
		else
			b[r-1]=r;
		}
	};
main()
	{arti af;
	for(int i=0;i<25;i++)
		{af.check();
		cout<<af.b[i]<<" ";
		}
	}
