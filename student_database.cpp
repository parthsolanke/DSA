/*

Author - Parth Solanke
Roll no. - SE62 (AI&DS)
Assignment no. - 02
Title: student database
 
 */

#include <iostream>
using namespace std;

class student 
{
	string name,lic,blood,div,claas,dob;
	int *roll;
	long telno;
	
	public:
		
		friend class teacher;
		
		student()//default constructor
		{
			roll = new int;
			name,lic,blood,div,claas,dob ="";
			telno = 0;
		}
		
	
	void get_data ()
	{
		cout<<"\n Enter name: ";
		cin>>name;
		cout<<"\n Enter roll no.: ";
		cin>>*roll;
		cout<<"\n Class: ";
		cin>>claas;
		cout<<"\n Division: ";
		cin>>div;
		cout<<"\n Mob no.: ";
		cin>>telno;
		cout<<"\n DOB: ";
		cin>>dob;
		cout<<"\n License no.: ";
		cin>>lic;
		cout<<"\n Blood group: ";
		cin>>blood;
	}
	
	student (student & z)       
	{
	  this->name=z.name;				
      this->claas=z.claas;
      this->div=z.div;
      this->roll=z.roll;
      this->telno=z.telno;
      this->blood=z.blood;
      this->dob=z.dob;
	}
	
	~student()
	{
		delete roll;
	}
	
	inline static void header()
	{
		cout<<"__________Student database system__________";
		cout<<"\n name, roll no., division, class, dateofbirth, mobile, blood group, address, license number";
	}
	
	void display()
	{
		cout<<name<<"\t"<<"\n"<<*roll<<"\t"<<"\n"<<claas<<"\t"<<"\n"<<div<<"\t"<<"\n"<<telno<<"\t"<<"\n"<<dob<<"\t"<<"\n"<<lic<<"\t"<<"\n"<<blood;
	}
};

class teacher
{
		string id;
	public:    
		teacher()
		{
			id="";
		}
	
	void get_teach_data()
	{
		cout<<"\n Enter Teacher ID: ";
		cin>>id;
	}
	
	void display_teach(student &obj,string t_d)
		{
		try
		{
			if(obj.div==t_d) 
			{
				cout<<"\n Students data of your division: ";
				obj.display();
				cout<<endl;
			}
			else
			{
				throw(obj.div);
			}
			}
			catch(string div)  
			{
				cout<<"\nError: Student & Teacher division not matched";
				cout<<endl;
				}	
		}		
};

int main()
{
 student s[10];
 teacher t;
 int ch,ct=0;
 string teach_div;
 do
 {
   cout<<"________Student information system________";
   cout<<"\n 1.Enter student data: ";
   cout<<"\n 2.Display student data: ";
   cout<<"\n 3.Copy constructor: ";
   cout<<"\n 4.Teacher & Student division verification: ";
   cout<<"\n 5.Exit ";
   cout<<"\n Enter choice: ";
   cin>>ch;
   cout<<"\n";
   
   switch(ch)
   {
   	case 1:
   		s[ct].get_data();
   		ct++;
   		cout<<endl;
   		break;
   	
   	case 2:
   		student::header();
   		cout<<"\n";
   		for(int i = 0;i<ct;i++)
   		{
   			s[i].display();
		}
		cout<<endl;
		break;
	
	case 3:
		{
		cout<<" Copy info -";
		student a;
		a.get_data();
		student b(a);
		cout<<"\n";
		student::header();
		b.display();
		}
		break;
		
	case 4:
		t.get_teach_data();
		cout<<"\n Enter Teacher's division: ";
		cin>>teach_div;
		for(int i=0;i<ct;i++)
		{
			t.display_teach(s[i],teach_div);   
		}
		break;
			
    case 5:
   		exit(0);
   	
	}
		
 }
 while (ch != 5);

 return 0;
}