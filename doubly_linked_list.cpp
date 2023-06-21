#include <iostream>
using namespace std;
class Node
{
public:
bool Digit;
Node *prev, *next;
friend class Binary;
Node()
{
prev=NULL, next = NULL;
}
Node(bool B)
{
Digit = B;
prev, next = NULL;
}
};
class Binary
{
public:
Node *start, *end;
bool N;
Binary()
{
start = end = NULL;
}
///////////////////////////////////////////////////////////////////
void Convert(int Num)
{
bool Remainder;
Node *p;
Remainder = Num%2;
Num = Num/2;
end = new Node(Remainder);
start=new Node(Remainder);
end = start;
while(Num != 0)
{
Remainder = Num%2;
Num = Num/2;
p = new Node(Remainder);
start->prev = p;
p->next = start;
p->prev=NULL;

start = p;
}
}

void Display()
{
Node *p ;
cout<<"\nBinary:";
p = start;
while(p!=NULL)
{
cout<<p->Digit;
p=p->next;
}
}

void s1comp()
{
cout<<"\n1s Compliment:";
Node *p ;
p = start;
while(p!=NULL)
{
if(p->Digit==0)
{
p->Digit=1;
}
else
{
p->Digit=0;
}
cout<<p->Digit;
p=p->next;
}
}

void s2comp()
{
Node *p ;
p = end;
cout<<"\n2nd Compliment:";
int cnt=0;
while(p!=NULL)
{
while(cnt==0 && p->Digit==1 )
{
p->Digit=0;
p=p->prev;
}
cnt++;
if (cnt==1 && p->Digit==0)

{
p->Digit=1;
p=p->prev;
cnt++;
}
else
{
p=p->prev;
}
}
p = start;
while(p!=NULL)
{
cout<<p->Digit;
p=p->next;
}
}

Binary add(Binary a1,Binary a2)
{
Binary sum;
Node *p,*q;
p=a1.end;
q=a2.end;

bool c=0;
while(p!=NULL && q!=NULL)
{
if(p->Digit==0 && q->Digit==0 && c==0)
{
p->Digit=0;

c=0;
}
else if(p->Digit==0 && q->Digit==0 && c==1)
{
p->Digit=1;

c=0;
}
else if(p->Digit==1 && q->Digit==0 && c==0)
{
p->Digit=1;

c=0;
}
else if(p->Digit==0 && q->Digit==1 && c==0)
{
p->Digit=1;

c=0;

}
else if(p->Digit==0 && q->Digit==1 && c==1)
{
p->Digit=0;

c=1;
}
else if(p->Digit==1 && q->Digit==0 && c==1)
{
p->Digit=0;

c=1;
}
else if(p->Digit==1 && q->Digit==1 && c==0)
{
p->Digit=0;

c=1;
}
else if(p->Digit==1 && q->Digit==1 && c==1)
{
p->Digit=1;

c=1;
}
/*else
{
return ;
}*/
p=p->prev;
q=q->prev;
}
if(p==NULL)
{
//cout<<p;
cout<<"ko\n";
// cout<<"hello";
p=q;
cout<<p;
while(p!=NULL)
{
// cout<<"h1";
if(c==1 && p->Digit==1 )
{
// cout<<"123";
p->Digit=0;
c=1;
}
else if(c==1 && p->Digit==0)
{
cout<<"456";

p->Digit=1;
c=0;
}
else if(c==0 && p->Digit==1)
{
//cout<<"456";
p->Digit=1;
c=0;
}
else
{
p->Digit=0;
c=0;
}
p=p->prev;
}
}
if(c==1)
{
Node *t=new Node();
p->prev=t;
t->next=p;
p=t;
p->Digit=1;
}
cout<<"\nADDition:";
//a1.Display();
return a1;
}
};
///////////////////////////////////////////////////////////////////////
int main()
{
int n,s1,s2;
cout<<"Enter the number to convert into binary:";
cin>>n;
Binary A1,n1,n2,sum,X;
A1.Convert(n);
A1.Display();
A1.s1comp();
A1.s2comp();
cout<<"\nEnter two numbers\n";
cout<<"Enter 1st no:";
cin>>s1;
cout<<"Enter 2nd no:";
cin>>s2;
n1.Convert(s1);
n1.Display();
n2.Convert(s2);
n2.Display();
X=sum.add(n1,n2);

X.Display();
return 0;
}