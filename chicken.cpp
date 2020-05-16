#include<iostream>
using namespace std;
class chicken
{int x;
double pr;
public:
chicken()
          {
cout<<"enter the weight of the chicken in grams";
cin>>x;
          }


double protein()
          {
pr=(x*31)/100;
          }



void chicken_protein()
             {
cout<<"protein in "<<x<<"gms of chicken is:"<<pr<<endl;
          
   }

};
main()
{
chicken ob;
ob.protein();
ob.chicken_protein();
}
