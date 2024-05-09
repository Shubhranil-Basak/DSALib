#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();
typedef pair<int, int> pii;

// Function to perform the Floyd-Warshall algorithm
vector<vector<int>> floydWarshall(const vector<vector<pii>>& adj_list) {
    int n = adj_list.size();
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Initialize distances based on the adjacency list
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        for (auto neighbor : adj_list[i]) {
            int v = neighbor.second;
            int weight = neighbor.first;
            dist[i][v] = weight;
        }
    }

    // Applying the Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes (n) and number of edges (m): ";
    cin >> n >> m;

    vector<vector<pii>> graph(n);

    cout << "Enter the edges in the format (u v w) representing edge from u to v with weight w:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        // If the graph is undirected, add the reverse edge as well
        // graph[v].push_back({w, u}); // Uncomment this line for undirected graph
    }

    vector<vector<int>> shortest_distances = floydWarshall(graph);

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    cout << "Shortest distances from node " << source << " to all other nodes:\n";
    for (int i = 0; i < n; ++i) {
        if (shortest_distances[source][i] == INF) {
            cout << "INF ";
        } else {
            cout << shortest_distances[source][i] << " ";
        }
    }
    cout << endl;

    return 0;
}
