//204251 Naveen Kumar Tyagi
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 21
#define N 21
using namespace std;

struct comp
{
    bool operator()(pair<pair<int, int>, int> &value, pair<pair<int, int>, int> &key)
    {
        return (value.second < key.second);
    }
};

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
    vector<pair<pair<int, int>, int>> pMST; // For prim MST and cost
    vector<pair<pair<int, int>, int>> kMST; // For kruskal MST and cost

    int find(int * parent, int i){
        if(parent[i]==-1)
            return i;
        return find(parent,parent[i]);
    }
    void unio(int * parent,int x, int y){
        parent[x]=y;
    }
    Graph()
    {
        initialise();
    }

    void edge(int x, int y, int cost)
    {
        adj_mat[x - 1][y - 1] = cost;
        adj_mat[y - 1][x - 1] = cost;
    }

    // bool dfs(int x,int y)
    // {
    //     // fill_n(visited, MAX, 0);
    //     Stack S;
    //     S.push(x - 1);
    //     while (!S.isEmpty())
    //     {
    //         int temp = S.peek();
    //         bool flag = true;
    //         for (int j = 0; j < nodes; j++)
    //         {
    //             if (adj_mat[temp][j] && visited[j]==1)
    //             {
    //                 S.push(j);
    //                 visited[j] = 1;
    //                 if(j==y-1){
    //                     return true;
    //                 }
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if (flag)
    //         {
    //             S.pop();
    //             // cout << "backtrack\n";
    //         }
    //     }
    //     return false;
    // }

    bool primMST()
    {
        fill_n(visited, MAX, 0);
        visited[0] = 1;
        int edges = 0; //counter
        while (edges < nodes - 1)
        {
            int min = 1e9, pos1, pos2;
            bool flag = true;
            for (int i = 0; i < nodes; i++)
            {
                if (visited[i])
                {
                    for (int j = 0; j < nodes; j++)
                    {
                        if (adj_mat[i][j] && !visited[j])
                        {
                            if (min > adj_mat[i][j])
                            {
                                pos1 = i;
                                pos2 = j;
                                min = adj_mat[i][j];
                                flag = false;
                            }
                        }
                    }
                }
            }
            if (flag)
                break;

            pMST.emplace_back(make_pair(pos1 + 1, pos2 + 1), adj_mat[pos1][pos2]);
            visited[pos2] = 1;
        }

        if (pMST.size() != nodes - 1)
            return false;

        return true;
    }

    bool krusMST()
    {
        int parent[1000];
        fill_n(parent,nodes,-1);
        vector<pair<pair<int, int>, int>> edges;
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                if (adj_mat[i][j])
                {
                    edges.emplace_back(make_pair(i + 1, j + 1), adj_mat[i][j]);
                }
            }
        }
        sort(edges.begin(), edges.end(), comp());
        int n_edges = 0, i = 0;
        while (n_edges < nodes - 1 && i < edges.size())
        {
            int x = edges[i].first.first;
            int y = edges[i].first.second;
            // int cost = edges[].second;
            i++;
            if(find(parent,x-1)!=find(parent,y-1)){
                unio(parent,x-1,y-1);
                kMST.emplace_back(edges[i - 1]);
                n_edges++;
            }

        }
        if (kMST.size() != nodes - 1)
            return false;

        return true;
    }
};

//------------------------------------------------
int main()
{

    Graph G;
    G.nodes = 9; // no. of nodes
    G.edge(1, 2, 10);
    G.edge(2, 3, 25);
    G.edge(3, 4, 12);
    G.edge(2, 5, 15);
    G.edge(3, 6, 16);
    G.edge(5, 6, 20);

    G.edge(4, 7, 21);
    G.edge(6, 7, 20);
    G.edge(5, 8, 32);

    G.edge(6, 9, 7);
    G.edge(8, 9, 9);

    if (G.primMST())
    {
        cout << "\nUsing Prim algorithm\n";
        cout << "\nEDGES\t\tCOST\n";
        for (int i = 0; i < G.pMST.size(); i++)
        {
            cout << G.pMST[i].first.first << " - " << G.pMST[i].first.second << "\t\t" << G.pMST[i].second << endl;
        }
    }
    else
        cout << "No prim Spanning Tree.\n";

    if (G.krusMST())
    {
        cout << "\nUsing Kruskal algorithm\n";
        cout << "\nEDGES\t\tCOST\n";
        for (int i = 0; i < G.kMST.size(); i++)
        {
            cout << G.kMST[i].first.first << " - " << G.kMST[i].first.second << "\t\t" << G.kMST[i].second << endl;
        }
    }
    else
        cout << "\nNo kruskal Spanning Tree.\n";
}
