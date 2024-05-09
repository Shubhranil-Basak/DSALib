#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& visited, vector<vector<int>>& graph, stack<int>& st) {
    visited[node] = 1;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph, st);
        }
    }
    st.push(node);
}

void transpose(int node, vector<int>& visited, vector<vector<int>>& reverse_graph, vector<int>& component) {
    visited[node] = 1;
    component.push_back(node);
    for (int neighbor : reverse_graph[node]) {
        if (!visited[neighbor]) {
            transpose(neighbor, visited, reverse_graph, component);
        }
    }
}

vector<vector<int>> findStronglyConnectedComponents(vector<vector<int>>& graph, vector<vector<int>>& reverse_graph) {
    int n = graph.size();
    vector<int> visited(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, graph, st);
        }
    }
    vector<vector<int>> components;
    fill(visited.begin(), visited.end(), 0);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            vector<int> component;
            transpose(node, visited, reverse_graph, component);
            components.push_back(component);
        }
    }
    return components;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    vector<vector<int>> graph(n), reverse_graph(n);
    cout << "Enter the edges in the form of u, v, w:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
    }
    vector<vector<int>> components = findStronglyConnectedComponents(graph, reverse_graph);
    cout << "Strongly Connected Components:\n";
    for (const vector<int>& component : components) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}