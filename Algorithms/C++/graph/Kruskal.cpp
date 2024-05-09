#include <bits/stdc++.h>
using namespace std;


// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to compare edges based on their weights
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find the parent of a node in the disjoint set
int findParent(int node, vector<int>& parent) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent);
}

// Function to perform union of two sets
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int numNodes) {
    // Sort the edges based on their weights
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Edge> mst; // Stores the edges of the minimum spanning tree
    vector<int> parent(numNodes); // Stores the parent of each node in the disjoint set
    vector<int> rank(numNodes, 0); // Stores the rank of each node in the disjoint set

    // Initialize the parent of each node as itself
    for (int i = 0; i < numNodes; i++)
        parent[i] = i;

    // Iterate through all the edges in ascending order of their weights
    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        // Check if including this edge forms a cycle
        if (findParent(u, parent) != findParent(v, parent)) {
            // Add the edge to the minimum spanning tree
            mst.push_back({u, v, weight});
            // Perform union of the sets containing u and v
            unionSets(u, v, parent, rank);
        }
    }

    return mst;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<Edge> edges(numEdges);
    cout << "Enter the edges in the form (u, v, weight):\n";
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    vector<Edge> mst = kruskalMST(edges, numNodes);

    cout << "Edges in the minimum spanning tree:\n";
    for (const Edge& edge : mst) {
        cout << "(" << edge.u << ", " << edge.v << ", " << edge.weight << ")\n";
    }

    return 0;
}