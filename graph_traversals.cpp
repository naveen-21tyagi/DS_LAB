//204251 Naveen Kumar Tyagi
#include <iostream>
#define MAX 21
#define N 21
using namespace std;

class Stack
{
    int top;
    int arr[N];

public:
    Stack()
    {
        top = -1;
    }
    int pop()
    {
        if (top < 0)
        {
            return -1;
        }
        return arr[top--];
    }
    bool push(int x)
    {
        if (top >= N - 1)
        {
            return false;
        }
        arr[++top] = x;
        return true;
    }
    int peek()
    {
        if (top < 0)
        {
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
};

//----------------------------------------------------

class Queue
{
    int arr[N], size = 0, f = -1, l = -1;
    //size = no. of elements

public:
    void EnQueue(int x)
    {
        if (size == N)
        {
            return;
        }
        else if (f == -1 && l == -1)
        {
            f = l = 0;
            arr[l] = x;
            size++;
        }
        else
        {
            l = (l + 1) % N;
            arr[l] = x;
            size++;
        }
    }
    int DeQueue()
    {
        if (size == 0)
        {
            return -1;
        }
        else
        {
            int x = arr[f];
            f = (f + 1) % N;
            size--;
            if (size == 0)
                f = l = -1;
            return x;
        }
    }
    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }
    void display()
    {
        int i = f;
        cout << "Queue: ";

        while (i != l)
        {
            cout << arr[i] << " ";
            i = (i + 1) % N;
        }

        cout << arr[i] << endl;
    }
};
//------------------------------------------------------
int adj_mat[MAX][MAX], visited[MAX];
//--------------------------------------------------

class Graph
{
private:
    void initialise()
    {
        for (int i = 0; i < MAX; i++)
        {
            fill_n(adj_mat[i], MAX, 0);
        }
    }

public:
    int nodes;
    Graph()
    {
        initialise();
    }

    void edge(int x, int y)
    {
        adj_mat[x - 1][y - 1] = 1;
    }
    void dfs(int node)
    {
        Stack S;
        S.push(node - 1);
        visited[node - 1] = 1;
        cout << node << "\n";
        while (!S.isEmpty())
        {
            int temp = S.peek();
            bool flag = true;
            for (int j = 0; j < nodes; j++)
            {
                if (adj_mat[temp][j] == 1 && visited[j] == 0)
                {
                    cout << j + 1 << "\n";
                    S.push(j);
                    visited[j] = 1;
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                S.pop();
                // cout << "backtrack\n";
            }
        }
        fill_n(visited, MAX, 0);
    }
    void bfs(int node)
    {
        Queue Q;
        Q.EnQueue(node - 1);
        while (!Q.isEmpty())
        {
            // Q.display();
            int temp = Q.DeQueue();
            visited[temp] = 1;
            cout << temp + 1 << "\n";
            for (int j = 0; j < nodes; j++)
            {
                if (adj_mat[temp][j] == 1 && visited[j] == 0)
                {
                    Q.EnQueue(j);
                }
            }
        }
        fill_n(visited, MAX, 0);
    }
};
//------------------------------------------------
int main()
{

    //     1--->2<---3--->4
    //          |    |             2-->5   &  6-->3
    //          5--->6--->7
    //          |         |        5-->8  &  7-->10
    //          8--->9    10

    Graph G;
    G.nodes = 10; // no. of nodes
    G.edge(1, 2);
    G.edge(2, 5);
    G.edge(3, 2);
    G.edge(3, 4);

    G.edge(5, 6);
    G.edge(5, 8);

    G.edge(6, 3);
    G.edge(6, 7);

    G.edge(7, 10);
    G.edge(8, 9);

    cout << "\n----DFS----\n";
    G.dfs(1);
    cout << "\n\n\n-----BFS----\n";
    G.bfs(1);
}
