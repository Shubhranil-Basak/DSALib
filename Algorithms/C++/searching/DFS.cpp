#include <bits/stdc++.h>
using namespace std;


// Function to perform DFS traversal on a directed graph
void DFS(vector<vector<pair<int, int>>>& graph, int start) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    stack<int> stk;

    stk.push(start);
    visited[start] = true;

    while (!stk.empty()) {
        int currNode = stk.top();
        stk.pop();

        cout << currNode << " ";

        for (auto neighbor : graph[currNode]) {
            int nextNode = neighbor.first;
            if (!visited[nextNode]) {
                stk.push(nextNode);
                visited[nextNode] = true;
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<pair<int, int>>> graph(numNodes);

    cout << "Enter the edges in the form of u, v, w (u -> v with weight w):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "DFS traversal path: ";
    DFS(graph, startNode);

    return 0;
}