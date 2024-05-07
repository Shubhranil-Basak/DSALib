#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int INF = numeric_limits<int>::max();

vector<int> bellmanFord(const vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> distances(n, INF);
    distances[source] = 0;

    // Relax edges up to (n-1) times to find shortest paths
    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (const auto& neighbor : graph[u]) {
                int v = neighbor.second;
                int weight = neighbor.first;

                // Relax the edge (u, v)
                if (distances[u] != INF && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }
    }

    // Check for negative-weight cycles (perform one more iteration)
    for (int u = 0; u < n; ++u) {
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.second;
            int weight = neighbor.first;

            // If we can still relax the edge (u, v), there's a negative-weight cycle
            if (distances[u] != INF && distances[u] + weight < distances[v]) {
                // Set distance to a large negative value to indicate a negative cycle
                distances[v] = -INF;
            }
        }
    }

    return distances;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes (n) and number of edges (m): ";
    cin >> n >> m;

    // Graph representation using adjacency list (vector of vectors of pairs)
    vector<vector<pii>> graph(n);

    cout << "Enter the edges in the format (u v w) representing edge from u to v with weight w:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        // If the graph is undirected, add the reverse edge as well
        // graph[v].push_back({w, u}); // Uncomment this line for undirected graph
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    // Use Bellman-Ford algorithm to find shortest paths (handles negative weights)
    vector<int> distances = bellmanFord(graph, source);

    // Output the shortest distances from the source node
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        if (distances[i] == INF) {
            cout << "Node " << i << ": INF (No path)\n";
        } else if (distances[i] == -INF) {
            cout << "Node " << i << ": -INF (Negative cycle)\n";
        } else {
            cout << "Node " << i << ": " << distances[i] << '\n';
        }
    }

    return 0;
}