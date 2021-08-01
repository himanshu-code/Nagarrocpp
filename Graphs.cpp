#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    void dfsHelper(T src, unordered_map<T, bool> &visited)
    {
        visited[src] = true;
        cout << src << " ";
        for (auto children : adjList[src])
        {
            if (!visited[children])
            {
                dfsHelper(children, visited);
            }
        }
    }

public:
    unordered_map<T, list<T>> adjList;
    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-->";
            for (auto neighbours : node.second)
            {
                cout << neighbours << " ";
            }
            cout << endl;
        }
    }
    void bfs(T src)
    {
        queue<T> q;
        q.push(src);
        unordered_map<T, bool> visited;
        visited[src] = true;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            cout << node << " ";
            for (auto neighbours : adjList[node])
            {
                if (!visited[neighbours])
                {
                    q.push(neighbours);
                    visited[neighbours] = true;
                }
            }
        }
        cout << endl;
    }
    int SSSP(T src, T des)
    {
        queue<T> q;
        q.push(src);
        unordered_map<T, bool> visited;
        unordered_map<T, int> distance;
        unordered_map<T, T> parent;
        distance[src] = 0;
        visited[src] = true;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            for (auto neighbours : adjList[node])
            {
                if (!visited[neighbours])
                {
                    q.push(neighbours);
                    visited[neighbours] = true;
                    distance[neighbours] = distance[node] + 1;
                    parent[neighbours] = node;
                }
            }
        }
        cout << "Path followed:";
        T x = des;
        while (x != src)
        {
            cout << x << "<--";
            x = parent[x];
        }
        cout << src << endl;
        return distance[des];
    }
    void dfs(T src)
    {
        unordered_map<T, bool> visited;
        dfsHelper(src, visited);
        int components = 1;
        for (auto node : adjList)
        {
            if (!visited[node.first])
            {
                components++;
                dfsHelper(node.first, visited);
            }
        }
        cout << endl
             << "Total component" << components << endl;
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(1, 4);
    g.addEdge(5, 4);
    g.addEdge(5, 6);
    g.print();
    g.bfs(1);
    cout << "Min distance between 1 and 6" << g.SSSP(1, 6) << endl;
    g.dfs(1);
    return 0;
}