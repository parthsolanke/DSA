#include<iostream>
using namespace std;

// creating a node for the binary search tree
class Node
{
    // declaring the data members with public access specifier so that they can be accessed outside the class
    public:
        int data;
        Node *left;
        Node *right;

        //constructor to initialize the data members
        Node(int value)
        {
            data = value;
            left = NULL;
            right = NULL;
        }
};

class BST
{
    public:
        // data member is the root node of the binary search tree
        Node *root;
        
        // constructor to initialize the root node
        BST()
        {
            root = NULL;
        }

        // membe rfunctions declarations
        void insert(int);
        int longestPathFromRoot();
        int longestPathFromRootRecursive(Node *);
        int findMin();
        bool search(int);
        void swap();
        void swapRecursive(Node *);

};

void BST::insert(int value)
{
    // creating a new node
    Node *newNode = new Node(value);

    // if the tree is empty
    if (root == NULL)
    {
        // making the new node as the root node
        root = newNode;
        // printing a success message
        cout << "Successfully inserted " << value << " in the tree." << endl;
        return;
    }

    // creating a pointer to traverse the tree
    Node *current = root;
    // creating another pointer that will keep track of the parent node of the current pointer
    Node *parent = NULL;

    // traversing the tree until the current pointer reaches NULL
    while (current != NULL)
    {
        // updating the parent pointer to the current pointer
        parent = current;

        // if the value is less than the data of the current node
        if (value < current->data)
        {
            // moving to the left child
            current = current->left;
        }
        // if the value is greater than the data of the current node
        else
        {
            // moving to the right child
            current = current->right;
        }
    }

    // if the value is less than the data of the parent node
    if (value < parent->data)
    {
        // making the new node as the left child of the parent node
        parent->left = newNode;
    }
    // if the value is greater than the data of the parent node
    else
    {
        // making the new node as the right child of the parent node
        parent->right = newNode;
    }

    // printing a success message
    cout << "Successfully inserted " << value << " in the tree." << endl;
}

int BST::longestPathFromRoot()
{
    // calling the recursive function to find the longest path from the root node
    return longestPathFromRootRecursive(root);
}

int BST::longestPathFromRootRecursive(Node *currentNode)
{
    // base case
    if (currentNode == NULL)
    {
        // returning 0 if the current node is NULL
        return 0;
    }

    // calling the function recursively for the left subtree
    int leftPath = longestPathFromRootRecursive(currentNode->left);
    // calling the function recursively for the right subtree
    int rightPath = longestPathFromRootRecursive(currentNode->right);

    // returning the maximum of the left and right subtree paths and adding 1 to it because we have to count the current node as well
    return 1 + max(leftPath, rightPath);
}

int BST::findMin()
{
    // if the tree is empty
    if (root == NULL)
    {
        // printing an error message and returning -1
        cerr << "Tree is empty." << endl;
        return -1;
    }

    // creating a pointer to traverse the tree
    Node *current = root;

    // traversing the tree to the leftmost node
    while (current->left != NULL)
    {
        current = current->left;
    }

    // returning the data of the leftmost node
    return current->data;
}

bool BST::search(int value)
{
    // creating a pointer to traverse the tree
    Node *current = root;

    // traversing the tree until the value is found or the pointer reaches NULL
    while (current != NULL)
    {
        // if the value is found
        if (current->data == value)
        {
            // returning true
            return true;
        }
        // if the value is less than the data of the current node
        else if (value < current->data)
        {
            // moving to the left child
            current = current->left;
        }
        // if the value is greater than the data of the current node
        else
        {
            // moving to the right child
            current = current->right;
        }
    }

    // returning false if the value is not found
    return false;
}

void BST::swap()
{
    // calling the recursive function to swap the left and right subtrees
    swapRecursive(root);
}

void BST::swapRecursive(Node *currentNode)
{
    // base case
    if (currentNode == NULL)
    {
        // returning if the current node is NULL
        return;
    }

    // swapping the left and right subtrees of the current node
    Node *temp = currentNode->left;
    currentNode->left = currentNode->right;
    currentNode->right = temp;

    // calling the function recursively for the left and right subtrees
    swapRecursive(currentNode->left);
    swapRecursive(currentNode->right);
}

int main()
{
    BST tree;
    int value;
    int ch;

    while(ch != 6)
    {
        cout << "1. Insert" << endl;
        cout << "2. Longest Path From Root" << endl;
        cout << "3. Find Minimum" << endl;
        cout << "4. Search" << endl;
        cout << "5. Swap" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter the value you want to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "The longest path from the root node is " << tree.longestPathFromRoot() << "." << endl;
                break;
            case 3:
                cout << "The minimum value in the tree is " << tree.findMin() << "." << endl;
                break;
            case 4:
                cout << "Enter the value you want to search: ";
                cin >> value;
                if (tree.search(value))
                {
                    cout << value << " is present in the tree." << endl;
                }
                else
                {
                    cout << value << " is not present in the tree." << endl;
                }
                break;
            case 5:
                tree.swap();
                cout << "The tree has been swapped." << endl;
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice." << endl;
        }

        cout << endl;
    }
}
