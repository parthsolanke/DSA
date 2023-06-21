#include<iostream>
#include<string.h>
using namespace std;

class Node
{
    public:
        string label;
        int section_count;
        Node *child[10];

        //constuctor
        Node()
        {
            label = "";
            section_count = 0;
            for (int i = 0; i < 10; i++)
            {
                child[i] = NULL;
            }
        }
};

class Book
{
    public:
        Node *root;

        //constructor
        Book()
        {
            root = NULL;
        }

        void create_tree();
        void display(Node *root);
};

void Book::create_tree()
{
    // creating a new node for the root
    root = new Node;

    // getting the name of the book
    cout << "\nEnter name of book : ";
    cin>>root->label;

    // getting the number of chapters
    cout << "\nEnter number of chapters in book : ";
    cin>>root->section_count;

    // getting details about the section nodes now
    for (int i = 0; i < root->section_count; i++)
    {
        // creating new node for the sections
        root->child[i] = new Node;

        cout<<"Enter name of chapter "<<"["<<i+1<<"]"<<" : ";
        cin>>root->child[i]->label;

        // getting the number of sections in the chapter
        cout<<"Enter number of sections in chapter "<<"["<<root->child[i]->label<<"]"<<" : ";
        cin>>root->child[i]->section_count;

        // getting details about the section nodes now
        for (int j = 0; j < root->child[i]->section_count; j++)
        {
            // creating new node for the subsections
            root->child[i]->child[j] = new Node;

            // getting the name of the section
            cout<<"Enter name of section "<<"["<<j+1<<"]"<<" : ";
            cin>>root->child[i]->child[j]->label;

            // getting the number of subsections in the section
            cout<<"Enter number of subsections in section "<<"["<<root->child[i]->child[j]->label<<"]"<<" : ";
            cin>>root->child[i]->child[j]->section_count;

            // getting details about the subsection nodes now
            for (int k = 0; k < root->child[i]->child[j]->section_count; k++)
            {
                // creating new node for the subsections
                root->child[i]->child[j]->child[k] = new Node;

                // getting the name of the subsection
                cout<<"Enter name of subsection "<<"["<<k+1<<"]"<<" : ";
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }

        cout<<endl;
    }
}

void Book::display(Node *root)
{
    // if root is empty then return
    if (root == NULL)
    {
        cout << "\nTree is empty\n";
        return;
    }
    // else display the tree
    else
    {
        cout << "\n---Book Hierarchy---";
        cout<<"\nBook name: "<<root->label<<endl;
        cout<<"\n";

        for (int i = 0; i < root->section_count; i++)
        {
            // printing the chapter names
            cout<<"Chapter "<<i+1<<": "<<root->child[i]->label<<endl;

            for (int j = 0; j < root->child[i]->section_count; j++)
            {
                // printing the section names
                cout<<"Section "<<j+1<<": "<<root->child[i]->child[j]->label<<endl;

                for (int k = 0; k < root->child[i]->child[j]->section_count; k++)
                {
                    // printing the subsection names
                    cout<<"Subsection "<<k+1<<": "<<root->child[i]->child[j]->child[k]->label<<endl;
                }
            }

            cout<<endl;
        }
    }
}

int main()
{
    Book b;
    b.create_tree();
    b.display(b.root);
    return 0;
}
