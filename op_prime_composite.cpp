#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int a,count;
	bool flag = true;
	count = 1;
	cin>>a;
	int b = sqrt(a);
	
	for(int i = 2 ; i<=b ; i++)
	{
		
		
		if (a%i==0)
		{
			flag = false;
		
		}
		
		if(!flag)
		{
			break;
		}
		
	}

	
	if(!flag)
	{
		cout<<"composit";
		
	}
	else
	{
		cout<<"prime";
	}
	
 return 0;	
}