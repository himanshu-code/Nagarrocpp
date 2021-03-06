#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool isBipartite(int src)
    {
        queue<int> q;
        q.push(src);
        int *colors = new int[V];
        for (int i = 0; i < V; i++)
        {
            colors[i] = -1;
        }
        colors[src] = 0;
        bool ans = true;
        while (!q.empty() && ans)
        {
            int u = q.front();
            q.pop();
            for (auto v : l[u])
            {
                if (colors[v] == -1)
                {
                    colors[v] = 1 - colors[u];
                    q.push(v);
                }
                else if (colors[v] == colors[u])
                {
                    return false;
                    break;
                }
            }
        }
        return true;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    if (g.isBipartite(0))
        cout << "YES" << endl;
    else
        cout << "NO";
    return 0;
}