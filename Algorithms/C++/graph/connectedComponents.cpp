#include <bits/stdc++.h>
using namespace std;


// Function to perform Depth First Search (DFS)
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, set<int>& component) {
    visited[node] = true;
    component.insert(node);

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, component);
        }
    }
}

// Function to find the number of connected components
int findConnectedComponents(vector<vector<int>>& graph, vector<set<int>>& components) {
    int numComponents = 0;
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            set<int> component;
            dfs(i, graph, visited, component);
            components.push_back(component);
            numComponents++;
        }
    }

    return numComponents;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numNodes);
    cout << "Enter the edges in the format (u, v, w):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<set<int>> components;
    int numComponents = findConnectedComponents(graph, components);

    cout << "Number of connected components: " << numComponents << endl;
    cout << "Nodes in each connected component:" << endl;
    for (int i = 0; i < numComponents; i++) {
        cout << "Component " << i + 1 << ": ";
        for (int node : components[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}