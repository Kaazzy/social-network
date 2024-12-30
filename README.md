# Graph Connectivity and Visualization

This project implements a graph connectivity checker and visualizer using C++ and the **SFML** (Simple and Fast Multimedia Library). It allows users to input a graph (vertices and edges), checks whether the graph is connected, and visualizes the graph using a circular layout.

---

## Features

1. **Graph Connectivity Check:**
   - Uses Depth First Search (DFS) to determine if the graph is connected.

2. **Graph Visualization:**
   - Displays the graph using nodes and edges arranged in a circular layout.
   - Utilizes the SFML library for rendering the graph.

---

## How It Works

1. **Input:**
   - The program prompts the user to enter the number of vertices and edges.
   - The user provides edges in the format `u v`, where `u` and `v` are vertices connected by an edge.

2. **Processing:**
   - The graph is represented as an adjacency list using a vector of pairs.
   - A DFS traversal checks if all nodes are reachable from any starting node.

3. **Output:**
   - Indicates whether the graph is connected or not.
   - Opens a graphical window to visualize the graph.

---

## Dependencies

1. **C++ Compiler:**
   - A modern C++ compiler (e.g., GCC, Clang, MSVC) that supports C++11 or later.

2. **SFML Library:**
   - Install SFML for graphical rendering. Visit [SFML Official Website](https://www.sfml-dev.org/) for installation instructions.

---

## Compilation and Execution

1. **Compilation:**
   - Use a C++ compiler with SFML linked. For example:
     ```bash
     g++ -o graph_visualizer main.cpp -lsfml-graphics -lsfml-window -lsfml-system
     ```

2. **Execution:**
   - Run the compiled executable:
     ```bash
     ./graph_visualizer
     ```

---

## Example Input

```plaintext
Enter the number of vertices: 5
Enter the number of edges: 4
Enter the edges (format: u v, where u and v are vertices connected by an edge):
0 1
1 2
2 3
3 4
```

**Output:**
```plaintext
The network is connected.
```

---

## How to Visualize

- After determining connectivity, the program opens a graphical window displaying the graph:
  - Nodes are arranged in a circular layout.
  - Edges are drawn between connected nodes.

- Close the visualization window by clicking the close button.

---

## File Structure

- **`main.cpp`**: Contains the source code for graph connectivity and visualization.
- **`LICENSE`**: License file (optional).

---

## License

## License

This project is licensed under the [GNU General Public License v3.0](LICENSE).
