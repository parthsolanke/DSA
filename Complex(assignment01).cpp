/*

Author - Parth Solanke
Roll no. - SE62 (AI&DS)
Assignment no. - 01
Title: Arithmetic operations on complex numbers using operator overloading
 
 */

#include<iostream>
#include<stdlib.h>

using namespace std;


class complex
{
	
int x,y;

public:
complex ()
{
x=y=0 ;
}
complex operator +(complex);
complex operator -(complex);
complex operator *(complex);
complex operator /(complex);
friend istream & operator >> (istream & in , complex & c)
{
cout<<"Enter real part - ";
in>>c.x;
cout<<"Enter imag part - ";
in>>c.y;
}

friend ostream & operator << (ostream & out , complex & c )
{
out<<" ("<<c.x<<" + "<<c.y<<"i"<<")"<<endl;
}

};

int main()
{

complex c1,c2,c3;
int z;

do
{
cout<<"___MENU___";
cout<<"\n1.Addition";
cout<<"\n2.Substraction";
cout<<"\n3.Multiplication";
cout<<"\n4.Division";
cout<<"\n5.Quit";
cout<<endl;
cout<<"\nEnter -";
cin>>z;
cout<<endl;
switch(z)
{
case 1 :
cout << "Enter 1st complex no."<<endl;
cin >> c1;
cout<<endl;
cout<<"Enter 2nd complex no. to add "<<endl;
cin>>c2;
c3 = c1+c2 ;
cout<<endl;
cout<<"Addition is:"<<c3;
break;

case 2 :
cout << "Enter 1st complex no."<<endl;
cin >> c1;
cout<<endl;
cout<<"Enter 2nd complex no. to substract "<<endl;
cin>>c2;
c3 = c1-c2;
cout<<endl;
cout<<"Substraction is:"<<c3;
break;

case 3 :
cout << "Enter 1st complex no."<<endl;
cin >> c1;
cout<<endl;
cout<<"Enter 2nd complex no. for multiplication "<<endl;
cin>>c2;
c3 = c1*c2;
cout<<endl;
cout<<"Multiplication is:"<<c3;
break;

case 4 :
cout << "Enter 1st complex no."<<endl;
cin >> c1;
cout<<endl;
cout<<"Enter 2nd complex no. to divide"<<endl;
cin>>c2;
c3 = c1/c2;
cout<<endl;
cout<<"Division is:"<<c3;
break;

//case 5 :
//exit(0);
}
cout<<endl;
}while(z != 5);

return 0;

}


complex complex :: operator +(complex c)
{
complex temp;
temp.x = x+ c.x;
temp.y = y +c.y;
return temp;
}

complex complex :: operator -(complex c)
{
complex temp;
temp.x = x- c.x;
temp.y = y-c.y;
return temp;
}

complex complex :: operator *(complex c)
{
complex temp;
temp.x = (x*c.x)-(y*c.y);
temp.y = (x*c.y)+(y*c.x);
return temp;
}

complex complex :: operator /(complex c)
{
complex temp;
float d;
d = ((c.x*c.x)+(c.y*c.y));
temp.x = ((x*c.x)+(y*c.y))/d;
return temp;
}