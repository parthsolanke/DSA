#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Node
{
public:
int PRN, Div;
string Name;
Node *next;
//Constructor
Node()
{
PRN = 0;
Div = 0;
Name = "";
next = NULL;
}
//Parameterized Constructor
Node (int P, int D, string N)
{
PRN = P;
Div = D;
Name = N;
}
friend class SLL;
};
class SLL
{
public:
Node *head;
Node *insert;
Node *end;
int PRN, Div, N;
string Name;
SLL ()
{
head = NULL;
insert = NULL;
end = NULL;
}
void Create()
{
// Function Name: Create
//Use: To create a linked list for the club members
//Head Node - President Info
cout<<"Enter President's information: \nName: ";
cin.ignore();
getline(cin, Name);
cout<<"PRN: ";
cin>>PRN;
cout<<"Divison: ";
cin>>Div;
head = new Node(PRN, Div, Name);

end = head;
cout<<"\nEnter the number of members of the Pinnacle Club (Excluding the Secretary): ";
cin>>N;
for (int i = 0; i<N; i++)
{
cout<<"\nEnter Member "<<i + 1<<"'s information: \nName: ";
cin.ignore();
getline(cin, Name);
cout<<"PRN: ";
cin>>PRN;
cout<<"Divison: ";
cin>>Div;
end->next = new Node(PRN, Div, Name);
end = end->next;
}
insert = end;
cout<<"\nEnter Secretary's information: \nName: ";
cin.ignore();
getline(cin, Name);
cout<<"PRN: ";
cin>>PRN;
cout<<"Divison: ";
cin>>Div;
end->next = new Node(PRN, Div, Name);
end = end->next;
end->next= NULL;
}
//Function Name: InsertMember
//Use: To insert a member into the club
void InsertMember()
{
int PRN, Div;
string Name;
cout<<"\nEnter new member's information: \nName: ";
cin.ignore();
getline(cin, Name);
cout<<"PRN: ";
cin>>PRN;
cout<<"Divison: ";
cin>>Div;
insert->next = new Node(PRN, Div, Name);
insert = insert->next;
insert->next= end;
}
//Function Name: deleteMember
//Use: To remove a member from the club
void deleteMember()
{
int SearchPRN;
Node *remove;
cout<<"\nEnter the PRN of the member to remove from the club: ";
cin>>SearchPRN;

if (SearchPRN == head->PRN)
{
remove = head;
head = head->next;
delete remove;
}
else
{
for (Node *temp = head; temp!=insert;temp = temp->next)
{
if (temp->next->PRN == SearchPRN)
{
if (temp->next == insert)
insert = temp;
remove = temp->next;
temp->next = temp->next->next;
delete remove;
if (temp == insert)
break;
}
}
}
if (SearchPRN == end->PRN)
{
remove = end;
insert->next = NULL;
end = insert;
delete remove;
}
}
//Function Name: Count
//Use: To count the number of members in the club
void Count()
{
int Count = 0;
for (Node *temp = head; temp!=insert;temp = temp->next)
{
Count++;
}
cout<<"\n Total number of student in the Pinnacle Club: "<<Count;
}
//Function Name: Display
//Use: To display the list of all the members of the club
void Display()
{
cout<<"\n\nNAME\t\tDIV\t\tPRN\n";
for (Node *temp = head; temp!=NULL;temp = temp->next)
{
cout<<temp->Name<<"\t\t"<<temp->Div<<"\t\t"<<temp->PRN<<"\n";
}

cout<<"\nPresident: "<<head->Name;
cout<<"\nSecretary: "<<end->Name;
cout<<"\n";
}
//Function Name: Merge
//Use: To merge two lists of the club from different divisions
void Merge(SLL L2)
{
end->next = L2.head;
end = L2.end;
}
};
//Main Body
int main()
{
SLL L1, L2;
int Choice;
do
{
cout<<"\n1. Create Club";
cout<<"\n2. Insert Memeber";
cout<<"\n3. Delete Member";
cout<<"\n4. Display Club List";
cout<<"\n5. Merge List";
cout<<"\n6. Count Number of Members";
cout<<"\n7. Exit";
cout<<"\nEnter choice: ";
cin>>Choice;
//Menu -Driven
switch(Choice)
{
case 1:
L1.Create();
break;
case 2:
L1.InsertMember();
break;
case 3:
L1.deleteMember();
break;
case 4:
L1.Display();
break;
case 5:
cout<<"\nEnter the contents of the second List: ";
L2.Create();
L1.Merge(L2);
cout<<"\nThe lists have been merged\n";
break;
case 6:
L1.Count();
break;

case 7:
return 0;
default:
cout<<"Invalid Choice!";
}
}while(Choice != 8);
return 0;
}