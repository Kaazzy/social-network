#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS and mark visited nodes
void dfs(int node, vector<bool>& visited, const vector<pair<int, int>>& edges) {
    visited[node] = true;

    for (const auto& edge : edges) {
        if (edge.first == node && !visited[edge.second]) {
            dfs(edge.second, visited, edges);
        } else if (edge.second == node && !visited[edge.first]) {
            dfs(edge.first, visited, edges);
        }
    }
}

// Function to check if the graph is connected
bool isConnected(int vertices, const vector<pair<int, int>>& edges) {
    vector<bool> visited(vertices, false);

    // Start DFS from the first vertex
    dfs(0, visited, edges);

    // Check if all vertices are visited
    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}

int main() {
    int vertices, edgesCount;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    vector<pair<int, int>> edges;

    cout << "Enter the edges (format: u v, where u and v are vertices connected by an edge):\n";
    for (int i = 0; i < edgesCount; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    cout << "\nGraph edges:\n";
    for (const auto& edge : edges) {
        cout << edge.first << " - " << edge.second << endl;
    }

    if (isConnected(vertices, edges)) {
        cout << "\nThe network is connected.\n";
    } else {
        cout << "\nThe network is not connected.\n";
    }

    return 0;
}
