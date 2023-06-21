// assingnment 3

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class employee
{
	private :
		int emp_id,salary;
		string name;
		
	public:
		void get_data()
		{
			ofstream o1;
			o1.open("Employee_details.txt" , ios::app);
			
			if (o1.file())
			{
				cout<<"Error opening the file";
			}
			else 
			{
				cout<<"Enter Employee name: ";
				cin>>name;
				cout<<"Enter Employee Id: ";
				cin>>emp_id;
				cout<<"Enter salary";
				cin>>salary;
				
				o1<<name;
				o1<<"	";
				o1<<empid;
				o1<<"	";
				o1<<salary;
				o1.close()
				
			}
			
		void display()
		{	
		}
			
		}
		
}