#include <bits/stdc++.h>
using namespace std;


void dfs(int u, int &time, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap)
{
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            dfs(v, time, adj, visited, disc, low, parent, ap);

            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && children > 1)
            {
                ap[u] = true;
            }
            if (parent[u] != -1 && low[v] >= disc[u])
            {
                ap[u] = true;
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findArticulationPoints(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    vector<bool> visited(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<int> parent(V, -1);
    vector<bool> ap(V, false);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int time = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, time, adj, visited, disc, low, parent, ap);
        }
    }

    cout << "Articulation Points: ";
    for (int i = 0; i < V; i++)
    {
        if (ap[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E);
    cout << "Enter the edges in the format (u, v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    findArticulationPoints(V, edges);

    return 0;
}