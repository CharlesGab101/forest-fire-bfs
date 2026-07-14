// conversion of matrix 2d indexes into vertex numbers in the graph
//Example: [0][0] = 0, [0][1] = 1 and so on
void contruct_graph(int rows, int columns, Graph& graph, const std::vector<std::vector<int>>& matrix){
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            // include healthy and burned trees in connectivity (1 and 2)
            if (matrix[r][c] == 1 || matrix[r][c] == 2) {
                int current = r * columns + c; //convert [][] into node number 

                // check right
                if (c + 1 < columns && (matrix[r][c + 1] == 1 || matrix[r][c + 1] == 2)) {
                    int target = r * columns + c + 1;
                    //if (graph.checkEdge(current, target)){
                    graph.addEdge(current, target);
                    //}
                    //if (graph.checkEdge(target, current)){
                    graph.addEdge(target, current);
                    // }
                    //std::cout << "Added Edge from right" << std::endl;

                } 
                //check down
                if (r + 1 < rows && (matrix[r + 1][c] == 1 || matrix[r + 1][c] == 2)) {
                    int target = (r + 1) * columns + c;
                    //if (graph.checkEdge(current, target)){
                    graph.addEdge(current, target);
                    //}
                    //if (graph.checkEdge(target, current)){
                    graph.addEdge(target, current);
                    // }
                    //std::cout << "Added Edge from down" << std::endl;
                } 
                // check left
                if (c - 1 >= 0 && (matrix[r][c - 1] == 1 || matrix[r][c - 1] == 2)) {
                    int target = r * columns + c - 1;
                    //if (graph.checkEdge(current, target)){
                        graph.addEdge(current, target);
                    //}
                    //if (graph.checkEdge(target, current)){
                        graph.addEdge(target, current);

                   // }
                   //std::cout << "Added Edge left" << std::endl;
                } 
                 // check up
                if (r - 1 >= 0 && (matrix[r - 1][c] == 1 || matrix[r - 1][c] == 2)) {
                    int target = (r - 1) * columns + c; 
                    //if (graph.checkEdge(current, target)){
                        graph.addEdge(current, target);
                    //}
                    //if (graph.checkEdge(target, current)){
                        graph.addEdge(target, current);

                   // }
                   //std::cout << "Added Edge from up" << std::endl;
                }
                
            }

        }
  }
}