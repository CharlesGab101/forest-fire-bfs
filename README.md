# CPSC 335: Algorithm Engineering - Project 3

## 👥 Team

| Name | Role / Email |
| --- | --- |
| **Charles Edwill Gabut** | Student ([charles_g@csu.fullerton.edu](mailto:charles_g@csu.fullerton.edu)) |

---

## 🛠 Project Components

### 1. The Spread of Fire in a Forest (Project 3)
An environmental simulation and graph traversal algorithm designed to find the minimum number of days it takes for a wildfire to spread from a single initial source through a grid of trees.
*   **Objective:** Find the minimum number of days required for a fire to burn down all reachable healthy trees in a grid, or determine if some healthy trees remain unreachable.
*   **Logic:**
    *   **Graph Construction:** Converts a 2D forest matrix (where `1` is a healthy tree, `2` is the burning tree, and `0` is an empty space) into an adjacency list representation of a graph. Edges are created bidirectionally between adjacent valid tree nodes (up, down, left, right).
    *   **BFS Forest Fire Simulation:** Executes a Breadth-First Search (BFS) starting from the single burning tree node (`2`). It tracks the distance (days) to each reached tree and counts how many healthy trees are successfully burned.
    *   **Reachability Validation:** Compares the total count of reachable burned trees against the total count of healthy trees in the grid. If they match, it returns the maximum depth of the BFS (days); otherwise, it returns `-1` to indicate some trees were isolated and did not burn.
*   **Efficiency:** 
    *   **Time Complexity:** $\mathcal{O}(V + E)$ where $V$ is the total number of cells in the grid ($V = \text{rows} \times \text{columns}$) and $E$ is the number of connecting boundaries between adjacent trees. Both graph construction and the BFS traversal run in linear time with respect to the size of the graph.
    *   **Space Complexity:** $\mathcal{O}(V + E)$ to store the adjacency list representation of the forest grid and auxiliary vectors (`is_visited`, `steps`) for the traversal tracking.

---

## 💻 Tech Stack

| Category | Tools / Concepts |
| --- | --- |
| **Language** | C++ (Standard C++17) |
| **Algorithms** | Breadth-First Search (BFS), Graph Traversals |
| **Data Structures** | Custom Graph (Adjacency List), Custom Node, Queues, Vectors |

---

## 🚀 Getting Started

### Compilation
To compile the **Spread of Fire** executable, run the following command in your terminal:
```bash
algorithm_one_1_.sh
