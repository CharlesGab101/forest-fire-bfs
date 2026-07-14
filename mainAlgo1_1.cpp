#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <string>

#include "graph_1_.cpp"
#include "contruct_graph_1_.cpp"
#include "bfs_1_.cpp"

int check_for_avaliable_trees(const std::vector<std::vector<int>>& matrix);
int main() {
  int rows;
  int columns;
  std::vector<std::vector<int>> matrix;
  int total_zeros = 0;
  bool has_path = false;
  std::cout << "=============Welcome to Project 3 The Spread of Fire in a Forest============="
            << std::endl;

  while (true) {
    std::cout << "Enter Number of Rows: ";
    if (std::cin >> rows) {
      break;
    } else {
      std::cout << "Invalid Input! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
  }
  while (true) {
    std::cout << "Enter Number of columns: ";
    if (std::cin >> columns) {
      break;
    } else {
      std::cout << "Invalid Input! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
  }

  int counter = 0;
  int cooordinates_of_2 = -1;
  matrix = std::vector<std::vector<int>>(rows, std::vector<int>(columns, 0));
  std::cout << "\n";
  std::cout << "=======Input 1s, 0s, 2s (2 = burned tree), (0 = empty area no trees) and (1 for a healthy tree)=======\n";

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      int value;
      std::cout << "Enter value for position [" << i << "][" << j << "]: ";

      if (!(std::cin >> value)) {
        std::cout << "Invalid input! Please enter an integer (0, 1, or 2).\n";
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        j--; // redo this cell
        continue;
      }

      if (value == 0){
        total_zeros++;
      }

      if (value < 0 || value > 2) {
        std::cout << "Invalid Input! Only 0s, 1s, and 2s are allowed.\n";
        j--; // redo this cell
        continue;
      }

      if (value == 2) {
        if (counter >= 1) {
          std::cout << "Only one burned tree allowed! Try Again\n";
          j--; // redo this cell
          continue;
        }
        counter++;
        cooordinates_of_2 = i * columns + j;
      }

      matrix[i][j] = value;
    }
  }
  std::cout << "\nMatrix:\n";

     for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            std::cout << matrix[r][c] << " ";
            if (matrix[r][c] == 1) {
              has_path = true;
            }
        }
        std::cout << "\n";
    }


    if (cooordinates_of_2 == -1) {
      std::cout << "No burned tree (2) found in matrix. Please enter exactly one burned tree.\n";
      std::cout << "Aborting..." << std::endl;
      return 0;
    }

    

    
  std::string number_of_health_trees_burned = "0";
  Graph graph(rows * columns);
  graph.initialization(); // O(n)
  //conversion of matrix indexes to vertex numbers in graph from 0 to n - 1 (n = total # of vertices)
  contruct_graph(rows, columns, graph, matrix); // O(r x c) because it checks every index in the matrix where r = rows and c = columns

  int starting_num = cooordinates_of_2; //convert [][] into node number 
  
  int number_moves = bfs_spread_fire(starting_num, graph, rows * columns, number_of_health_trees_burned); // o(v + e)
  
  int total_trees_health_trees = (graph.getTotalVertices() - total_zeros);
  total_trees_health_trees = total_trees_health_trees - 1; // exclude the burned tree
  if(has_path == false) {
    std::cout << "\n\nMinimum number of days to burn all trees: " << "0" << std::endl; // if there is no healthy tree then the minimum number of days to burn all trees is 0
  } else if (total_trees_health_trees == std::stoi(number_of_health_trees_burned)) { // if the number of healthy treess burned is equal to the total number of health trees    
                                                                              // then we already know that all trees are burned.
    std::cout << "\n\nMinimum number of days to burn all trees: " << number_moves << std::endl;
  } else {
    std::cout << "\n\nMinimum number of days to burn all trees: " << "-1" << std::endl; //otherwise display -1 because not all trees are burned
  }
  



  //int num = graph.checkEdge(0, 1);

 // std::cout << num << std::endl;
   return 0;
  
}