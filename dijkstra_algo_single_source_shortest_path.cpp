//204251 Naveen Kumar Tyagi
#include <iostream>
#include <queue>
#include <vector>
#define PAIR pair<int, int>
using namespace std;
class Graph
{
    int v;
    vector<PAIR> *ad_ls;

public:
    Graph(int n)
    {
        v = n;
        ad_ls = new vector<PAIR>[v];
    }

    void edge(int u, int v, int w)
    {
        ad_ls[u - 1].emplace_back(make_pair(v - 1, w));
        ad_ls[v - 1].emplace_back(make_pair(u - 1, w));
    }

    void djik_st(int root)
    {

        priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

        vector<int> dist(v, 10000000);

        pq.push(make_pair(0, root - 1));
        dist[root - 1] = 0;
        while (!pq.empty())
        {
            auto p = pq.top();
            int u = p.second;
            pq.pop();

            for (int i = 0; i < ad_ls[u].size(); i++)
            {
                int v = ad_ls[u][i].first;
                int w = ad_ls[u][i].second;

                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        cout << "Vertex\t\t Distance\n";
        for (int i = 0; i < v; i++)
        {
            cout << i + 1 << "\t\t\t" << dist[i] << endl;
        }
    }
};

int main()
{
    Graph G(9);

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

    cout << "\nShortest distance of vertices of from vertex 1\n\n";
    G.djik_st(1);
}
