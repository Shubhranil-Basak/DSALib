#include <bits/stdc++.h>
using namespace std;


// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to compare edges based on weight
struct CompareEdges {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight;
    }
};

// Function to find the minimum spanning tree using Prim's algorithm
vector<Edge> primMST(vector<vector<pair<int, int>>>& graph, int startVertex) {
    int numVertices = graph.size();

    // Priority queue to store edges based on weight
    priority_queue<Edge, vector<Edge>, CompareEdges> pq;

    // Array to track visited vertices
    vector<bool> visited(numVertices, false);

    // Add all edges from the start vertex to the priority queue
    for (auto& edge : graph[startVertex]) {
        pq.push({startVertex, edge.first, edge.second});
    }

    visited[startVertex] = true;
    vector<Edge> mst; // Minimum spanning tree

    while (!pq.empty()) {
        Edge currentEdge = pq.top();
        pq.pop();

        int u = currentEdge.u;
        int v = currentEdge.v;
        int weight = currentEdge.weight;

        // If the edge leads to an unvisited vertex, add it to the MST
        if (!visited[v]) {
            visited[v] = true;
            mst.push_back({u, v, weight});

            // Add all edges from the newly visited vertex to the priority queue
            for (auto& edge : graph[v]) {
                pq.push({v, edge.first, edge.second});
            }
        }
    }

    return mst;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<pair<int, int>>> graph(numVertices);

    cout << "Enter the edges in the form (u, v, w):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    vector<Edge> mst = primMST(graph, startVertex);

    cout << "Edges in the minimum spanning tree:" << endl;
    for (const auto& edge : mst) {
        cout << "(" << edge.u << ", " << edge.v << ", " << edge.weight << ")" << endl;
    }

    return 0;
}