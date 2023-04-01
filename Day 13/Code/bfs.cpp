#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> bfs(vector<int>[], int);
int main()
{
    // vertices are considerd 1-index based
    int v, e;
    cin >> v >> e; // input : vertices edges
    vector<int> graph[v + 1];
    for (int i = 0; i < e; i++)
    {
        int source, destination;
        cin >> source >> destination;
        graph[source].push_back(destination);
        graph[destination].push_back(source);
    }

    for (auto i : bfs(graph, v))
    {
        cout << i << " ";
    }

    cout << endl;
}
vector<int> bfs(vector<int> graph[], int vertices)
{
    vector<int> res;
    vector<int> visited(vertices + 1);
    queue<int> q;
    for (int i = 1; i <= vertices; i++)
    {
        if (visited[i] == 0)
        {
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int top = q.front();
                q.pop();
                res.push_back(top);
                for (auto x : graph[top])
                {
                    if (visited[x] == 0)
                    {
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
        }
    }
    return res;
}