#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int node, vector<int> &visited, vector<int> graph[], vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);
    for (auto x : graph[node])
    {
        if (!visited[x])
        {
            dfs(x, visited, graph, ans);
        }
    }
}

int main()
{
    // vertices are considerd 1-index based
    int v, e;
    cin >> v >> e; // input : vertices edges
    vector<int> graph[v + 1];
    vector<int> ans;
    vector<int> visited(v + 1);
    for (int i = 0; i < e; i++)
    {
        int source, destination;
        cin >> source >> destination;
        graph[source].push_back(destination);
        graph[destination].push_back(source);
    }
    for (int i = 1; i < v + 1; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, graph, ans);
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
