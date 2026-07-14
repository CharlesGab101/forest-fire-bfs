#include <queue>
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <string>

int bfs_spread_fire(int starting_node, Graph& graph, int total_vertices, std::string& number_of_health_trees_burned) {
    std::vector<bool> is_visited(total_vertices, false);
    std::vector<int> steps(total_vertices, -1);
    
    int x = std::stoi(number_of_health_trees_burned); //track the number of healthy trees burned
                                                      //this one is important to check if all the healthy trees are burned or not
                                                      //we pass this by reference to update the number of healthy to the main function
    
    std::queue<int> vertex;
    std::queue<int> steps_queue;
    is_visited[starting_node] = true; //mark visited
    steps[starting_node] = 0; // set the starting vertex steps to 0
    vertex.push(starting_node); // push the starting vertex

    while(!vertex.empty()) { 
        int current = vertex.front();
        steps_queue.push(steps[current]);
        vertex.pop();

        Node* temp_node = graph.getAdjacencylist()[current]; // get the edges of each vertex
        while(temp_node != nullptr) {
            if (is_visited[temp_node->getID()] == false) { //check if visited
                is_visited[temp_node->getID()] = true; //mark visited
                steps[temp_node->getID()] = steps[current] + 1; // record the steps for each vertex
                x++; //count the number of healthy trees burned
                vertex.push(temp_node->getID());// push the vertex number 
            }
            temp_node = temp_node->getNext(); // iterates until it finds the target vertex
        }
    }
    number_of_health_trees_burned = std::to_string(x); //update the number of tress burned to the main function
    return steps_queue.back(); //returns the total steps of the target vertex


}