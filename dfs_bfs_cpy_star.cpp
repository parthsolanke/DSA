#include <iostream>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
class traversal
{
public:
    void create();
    void display();
    int n;
    void BFS();
    void DFS();
    void DFSVisit(int, bool[]);
    int vertex = 20;
    char vertces[20];
    char list[20][20];
};
void traversal::create()
{
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            list[i][j];
        }
    }
    cout << "Enter the number of vertces:\n";
    cin >> vertex;
    for (int i = 0; i < vertex; i++)
    {
        cout << "Enter the vertex:";
        cin >> vertces[i];
        list[i][0] = vertces[i];
    }
    cout << "Enter adjancy list:\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << "For vertex " << vertces[i] << " enter the number of connected  vertces : ";
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cout << "Enter " << j + 1 << " connected vertex\n";
            cin >> list[i][j + 1];
        }
        cout << "Connected vertex:\n";
        for (int j = 0; j < n; j++)
        {
            cout << list[i][j + 1] << "\t";
        }
        cout << endl;
    }
}
void traversal::display()
{
    cout << "Adjancy list:";
    for (int i = 0; i < vertex; i++)
    {
        cout << endl;
        for (int j = 0; j < vertex; j++)
        {
            cout << list[i][j] << "\t";
        }
    }
}
void traversal::BFS()
{
    cout << endl
         << "BFS Sequence:";
    int visited[vertex] = {0};
    queue<int> q;
    int start = 0;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << vertces[current] << " ";
        for (int i = 1; i < vertex; i++)
        {
            if (list[current][i] != '\0' && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
void traversal::DFSVisit(int v, bool visited[])
{
    cout << endl;
    visited[v] = true;
    cout << vertces[v] << " ";
    for (int i = 1; i < vertex; i++)
    {
        if (list[v][i] != '\0' && !visited[i])
        {

            DFSVisit(i, visited);
        }
    }
}
void traversal::DFS()
{
    cout << endl
         << "DFS Sequence:";
    bool *visited = new bool[vertex];
    for (int i = 0; i < vertex; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == false)
        {
            DFSVisit(i, visited);
        }
    }
}
int main()
{
    traversal t1;
    t1.create();
    t1.display();
    t1.BFS();
    t1.DFS();
    return 0;
}