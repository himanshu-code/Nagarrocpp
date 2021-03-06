#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> adjList;

public:
    Graph()
    {
    }
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
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto entry : i.second)
            {
                cout << entry << ", ";
            }
        }
        cout << endl;
    }
    void dfsHelper(T node, map<T, bool> &visited, list<T> &ordering)
    {
        visited[node] = true;
        for (T neighbour : adjList[node])
        {
            if (!visited[neighbour])
            {
                dfsHelper(neighbour, visited, ordering);
            }
        }
        ordering.push_front(node);
    }
    void dfsTopologicalSort()
    {
        map<T, bool> visited;
        list<T> ordering;
        for (auto i : adjList)
        {
            T node = i.first;
            if (!visited[node])
            {
                dfsHelper(node, visited, ordering);
            }
        }
        for (auto element : ordering)
        {
            cout << element << "->";
        }
    }
    void topologicalSort()
    {
        queue<T> q;
        map<T, bool> visited;
        map<T, int> indegree;
        for (auto i : adjList)
        {
            T node = i.first;
            visited[node] = false;
            indegree[node] = 0;
        }
        for (auto i : adjList)
        {
            T u = i.first;
            for (T v : adjList[u])
            {
                indegree[v]++;
            }
        }
        for (auto i : adjList)
        {
            T node = i.first;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << "->";
            for (T neighbour : adjList[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
    }
};
int main()
{
    Graph<string> g;
    g.addEdge("English", "Programming Logic", false);
    g.addEdge("Maths", "Programming Logic", false);
    g.addEdge("Programming Logic", "HTML", false);
    g.addEdge("Programming Logic", "Python", false);
    g.addEdge("Programming Logic", "Java", false);
    g.addEdge("Python", "Web Dev", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "JS", false);
    g.addEdge("JS", "Web Dev", false);
    g.addEdge("Java", "Web Dev", false);
    g.addEdge("Python", "Web Dev", false);
    g.dfsTopologicalSort();
    cout << endl;
    g.topologicalSort();
}