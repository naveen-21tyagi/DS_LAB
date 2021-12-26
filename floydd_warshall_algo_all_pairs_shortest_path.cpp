//204251 Naveen Kumar Tyagi
#include <iostream>
#define MAX 21
#define N 21
using namespace std;

int adj_mat[MAX][MAX], visited[MAX];

class Graph
{
private:
    void initialise()
    {
        for (int i = 0; i < MAX; i++)
        {
            fill_n(adj_mat[i], MAX, 100000);
        }
        for (int i = 0; i < MAX; i++)
        {
            adj_mat[i][i] = 0;
        }
    }
    int **sol_mat; // solution matrix

public:
    int vertices;
    Graph(int n)
    {
        vertices = n;
        initialise();

        sol_mat = new int *[n];
        for (int i = 0; i < n; i++)
        {
            sol_mat[i] = new int[n];
        }
    }

    void edge(int x, int y, int w)
    {
        adj_mat[x - 1][y - 1] = w;
        adj_mat[y - 1][x - 1] = w;
    }

    void floyd()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                sol_mat[i][j] = adj_mat[i][j];
            }
        }

        for (int k = 0; k < vertices; k++)
        {
            for (int i = 0; i < vertices; i++)
            {
                for (int j = 0; j < vertices; j++)
                {
                    if (sol_mat[i][j] > sol_mat[i][k] + sol_mat[k][j])
                    {
                        sol_mat[i][j] = sol_mat[i][k] + sol_mat[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << sol_mat[i][j] << "\t";
            }
            cout << endl;
        }
    }
};
//------------------------------------------------
int main()
{
    Graph G(5);
    G.edge(1, 3, 10);
    G.edge(1, 4, 15);
    G.edge(2, 4, 12);
    G.edge(2, 5, 7);
    G.edge(4, 5, 4);

    cout << "\nSolution Matrix using Floyd algorithm\n\n";
    G.floyd();
}
