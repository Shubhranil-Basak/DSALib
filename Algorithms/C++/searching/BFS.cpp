#include <bits/stdc++.h>
using namespace std;


// Function to perform BFS traversal in an undirected graph
vector<int> bfsTraversal(int startNode, int endNode, unordered_map<int, vector<pair<int, int>>>& graph) {
    vector<int> path;
    queue<int> q;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    q.push(startNode);
    visited[startNode] = true;
    parent[startNode] = -1;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        if (currentNode == endNode) {
            // Reconstruct the path from endNode to startNode
            int node = endNode;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            break;
        }

        for (auto neighbor : graph[currentNode]) {
            int neighborNode = neighbor.first;
            if (!visited[neighborNode]) {
                q.push(neighborNode);
                visited[neighborNode] = true;
                parent[neighborNode] = currentNode;
            }
        }
    }

    return path;
}

int main() {
    // Create an undirected graph
    unordered_map<int, vector<pair<int, int>>> graph;

    // Add edges to the graph
    int u, v, w;
    while (cin >> u >> v >> w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    
    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;
    int endNode;
    cout << "Enter the ending node: ";
    cin >> endNode;

    vector<int> path = bfsTraversal(startNode, endNode, graph);

    // Print the path taken
    cout << "Path: ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}