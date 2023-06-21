#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
    public:
        int vertices;
        int connected_vertices[20];
        int vertices_list[20];
        int adj_matrix[20][20];

        Graph()
        {
            vertices = 0;

            for (int i = 0; i < 20; i++)
            {
                connected_vertices[i] = 0;
            }

            for(int i=0;i<20;i++)
            {
                for(int j=0;j<20;j++)
                {
                    adj_matrix[i][j] = 0;
                }
            }

            for(int i=0;i<20;i++)
            {
                vertices_list[i] = 0;
            }
        }

        void create();
        void display();
        void BFS();
        void DFS();
};

void Graph::create()
{
    cout<<"\nEnter the number of vertices: ";
    cin>>vertices;

    for (int i = 0; i < vertices; i++)
    {
        cout << "Enter the "<<i+1<<" vertex: ";
        cin >> vertices_list[i];
        adj_matrix[i][0] = vertices_list[i];

        cout << "Enter the number of connected vertices to " << vertices_list[i] << ": ";
        cin >> connected_vertices[i];
        for (int j = 0; j < connected_vertices[i]; j++)
        {
            cout << "Enter " << j + 1 << " connected vertex: ";
            cin >> adj_matrix[i][j + 1];
        }

        cout<<endl;
    }
}

void Graph::display()
{
    cout<<"Adjacency Matrix: "<<endl;

    for(int i=0 ; i < vertices ; i++)
    {
        for(int j=0 ; j < connected_vertices[i] ; j++)
        {
            cout<<adj_matrix[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<endl;
}

void Graph::BFS()
{
    int visited[20];
    for(int i=0;i<20;i++)
    {
        visited[i] = 0;
    }

    queue<int> q;
    q.push(adj_matrix[0][0]);
    visited[0] = 1;

    cout<<"BFS sequence: ";

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        cout<<current<<"\t";

        for(int i=0;i<vertices;i++)
        {
            if(adj_matrix[i][0] == current)
            {
                for(int j=1;j<=connected_vertices[i];j++)
                {
                    for(int k=0;k<vertices;k++)
                    {
                        if(adj_matrix[k][0] == adj_matrix[i][j])
                        {
                            if(visited[k] == 0)
                            {
                                q.push(adj_matrix[i][j]);
                                visited[k] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Graph::DFS()
{
    int visited[20];
    for(int i=0;i<20;i++)
    {
        visited[i] = 0;
    }

    stack<int> s;
    s.push(adj_matrix[0][0]);
    visited[0] = 1;

    cout<<"DFS sequence: ";

    while(!s.empty())
    {
        int current = s.top();
        s.pop();

        cout<<current<<"\t";

        for(int i=0;i<vertices;i++)
        {
            if(adj_matrix[i][0] == current)
            {
                for(int j=1;j<=connected_vertices[i];j++)
                {
                    for(int k=0;k<vertices;k++)
                    {
                        if(adj_matrix[k][0] == adj_matrix[i][j])
                        {
                            if(visited[k] == 0)
                            {
                                s.push(adj_matrix[i][j]);
                                visited[k] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    Graph g;
    g.create();
    g.display();
    g.BFS();
    cout<<endl;
    g.DFS();
    cout<<endl;
    return 0;
}