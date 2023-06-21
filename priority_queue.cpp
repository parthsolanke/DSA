#include <iostream>
#include <string>
using namespace std;

class patient
{
    //data members
public:
    string name[10];
    int priority[10];
    int rear, front;
    int n;

    patient()
    {
        rear = -1;
        front = -1;
    }

    // function to insert data and its priority in queue
    void enqueue(string, int);
    // function to print the data of Queue
    void display();
    // function to delete the data from Queue
    void dequeue();

};

void patient::enqueue(string data, int p)
{
    int i;
    if ((front == 0) && (rear == n - 1)) // Check if Queue is full
        cout << "Queue is full";
    else
    {
        if (front == -1)
        { // if Queue is empty
            front = rear = 0;
            name[rear] = data;
            priority[rear] = p;
        }
        else
        {
            for (i = rear; i >= front; i--)
            {
                if (p > priority[i])
                {
                    name[i + 1] = name[i];
                    priority[i + 1] = priority[i];
                }
                else
                    break;
            }
            name[i + 1] = data;
            priority[i + 1] = p;
            rear++;
        }
    }
}

void patient::display()
{ // print the data of Queue
    int i;
    for (i = front; i <= rear; i++)
    {
        cout << "Patient's Name - " << name[i];
        switch (priority[i])
        {
        case 1:
            cout << " Priority - 'Checkup' " << endl;
            break;
        case 2:
            cout << " Priority - 'Non-serious' " << endl;
            break;
        case 3:
            cout << " Priority - 'Serious' " << endl;
            break;
        default:
            cout << "Invalid Priority" << endl;
            break;
        }
    }
}

void patient::dequeue()
{
    // function to delete the data from Queue from the front
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Deleted : " << name[front] << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}

int main()
{
    patient p;
    int choice, pty;
    string name;
    cout << "\nEnter the size of queue : ";
    cin >> p.n;
    do
    {
        cout << "\n1. Insertion \n2. Deletion \n3. Display \n4. Exit \n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the name of patient : ";
            cin >> name;
            cout << "Enter the priority of patient (3: serious, 2: non-serious, 1: genral checkup) : ";
            cin >> pty;
            p.enqueue(name, pty);
            break;
        case 2:
            p.dequeue();
            break;
        case 3:
            p.display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
