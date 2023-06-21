#include<iostream>
using namespace std;

class graph
{
    // data members
    int adj_mat[50][50];
    int edges;
    int min_edge;
    int min_cost;
    //flag to check if vertex is visited or not
    int flag[50];

    // constructor
    public:
        // n is number of vertices making it public so that it can be used in other functions
        int n;
        graph()
        {
            min_edge = 0;
            min_cost = 0;
            n = 0;
            // initializing edges to 1 cause 1st vertex is visited
            edges = 1;
            // initializing all flags to 0
            for(int i = 0; i <= n; i++)
            {
                flag[i] = 0;
            }
        }

        // member functions
        void create_graph();
        void display_graph();
        void find_mincost(int);
};

void graph::create_graph()
{
    // taking input for number of vertices
    cout<<"\nEnter the number of vertices: ";
    cin>>n;
    // initializing all flags to 0
    for(int i = 0; i <= n; i++)
    {
        flag[i] = 0;
    }

    // taking input the edges for adjacency matrix
    cout<<"\nEnter the adjacency matrix: \n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout<<"\nEdge "<<i<<"->"<<j<<": ";
            cin>>adj_mat[i][j];
            // if no edge is present then initialize it to 999 for not counting the edge as minimum
            if(adj_mat[i][j] == 0)
            {
                adj_mat[i][j] = 999;
            }
        }
    }

}

void graph::display_graph()
{
    cout<<"\nEntered adjacency matrix is: \n";

    for (int i = 1; i <= n; i++)
    {
        cout<<"\n";
        for (int j = 1; j <= n; j++)
        {
            cout<<"\t"<<adj_mat[i][j];
        }
    }

    cout<<"\n";
}

void graph::find_mincost(int n)
{
    // marking the 1st vertex as visited using index 1 from the flag array cause index 0 is not used while taking input
    flag[1] = 1;

    // declaring two variables to store the vertices of the minimum edge
    int y, z;

    // loop to traverse all the edges and find the minimum edge
    while(edges <= (n - 1))
    {
        // initializing min_edge to 999 so that it can be compared with the edges of the graph
        min_edge = 999;

        // traversing the adjacency matrix to find the minimum edge
        for (int i = 1; i <= n; i++)
        {
            // looking in the row of the vertex
            for (int j = 1; j <= n; j++)
            {
                // if the edge from adjecency matrix is less than the minimum edge and the vertex is visited and minimum edge is changed
                if (adj_mat[i][j] < min_edge)
                {
                    if (flag[i] != 0)
                    {
                        min_edge = adj_mat[i][j];
                        y = i;
                        z = j;
                    }
                }
            }
        }

        // now the vertex is visited then mark it as visited and add the minimum edge to the minimum cost
        if (flag[z] == 0 || flag[y] == 0)
        {
            // displaying the path with minimum cost
            cout<<"\nEdge "<<edges<<" from "<<y<<" to "<<z<<" with cost "<<min_edge;

            flag[z] = 1;
            min_cost += min_edge;
            edges++;
        }

        // now changing the minimum edge to 999 so that it can be compared with the other edges
        adj_mat[y][z] = adj_mat[z][y] = 999;

    }
    cout<<"\nMinimum cost is: "<<min_cost<<"\n";
}

int main()
{
    graph g;
    g.create_graph();
    g.display_graph();
    g.find_mincost(g.n);
    return 0;
}