#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// Function to perform DFS and mark visited nodes
void dfs(int node, vector<bool>& visited, const vector<pair<int, int>>& edges) {
    visited[node] = true;
    for (const auto& edge : edges) {
        if (edge.first == node && !visited[edge.second]) {
            dfs(edge.second, visited, edges);
        }
        else if (edge.second == node && !visited[edge.first]) {
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

// Function to draw the graph using SFML
void drawGraph(int vertices, const vector<pair<int, int>>& edges) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graph Visualization");

    // Calculate positions for nodes in a circular layout
    vector<sf::Vector2f> nodePositions(vertices);
    float centerX = 400, centerY = 300, radius = 200;
    for (int i = 0; i < vertices; ++i) {
        float angle = 2 * M_PI * i / vertices;
        nodePositions[i] = sf::Vector2f(centerX + radius * cos(angle), centerY + radius * sin(angle));
    }

    // Main loop for the window
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::White);

        // Draw edges
        for (const auto& edge : edges) {
            sf::Vertex line[] = {
                sf::Vertex(nodePositions[edge.first], sf::Color::Black),
                sf::Vertex(nodePositions[edge.second], sf::Color::Black)
            };
            window.draw(line, 2, sf::Lines);
        }

        // Draw nodes
        for (int i = 0; i < vertices; ++i) {
            sf::CircleShape node(15);
            node.setFillColor(sf::Color::Blue);
            node.setPosition(nodePositions[i].x - 15, nodePositions[i].y - 15);
            window.draw(node);
        }

        // Display the window
        window.display();
    }
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

    if (isConnected(vertices, edges)) {
        cout << "\nThe network is connected.\n";
    }
    else {
        cout << "\nThe network is not connected.\n";
    }

    // Draw the graph
    drawGraph(vertices, edges);

    return 0;
}