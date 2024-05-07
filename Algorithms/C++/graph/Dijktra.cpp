#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(const vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> distances(n, INF);
    distances[source] = 0;

    // Priority queue to store nodes to visit (min-heap based on distance)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int curr_node = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();

        // If the popped distance is greater than the recorded distance, skip
        if (curr_dist > distances[curr_node]) continue;

        // Explore neighbors of the current node
        for (const auto& neighbor : graph[curr_node]) {
            int next_node = neighbor.second;
            int weight = neighbor.first;

            // Calculate the new distance via the current node
            int new_dist = curr_dist + weight;

            // If found a shorter path to the neighbor, update and push to the queue
            if (new_dist < distances[next_node]) {
                distances[next_node] = new_dist;
                pq.push({new_dist, next_node});
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
        // graph[v].push_back({w, u}); // Uncomment this line for undirected graph
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    vector<int> distances = dijkstra(graph, source);

    // Output
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << distances[i] << '\n';
    }

    return 0;
}
