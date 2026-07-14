#include "list_node_1_.cpp"
#include <iostream>
class Graph {
    public:

    Graph() : total_vertices_(0) {}
    Graph(int vertices) : total_vertices_(vertices) {}


    void initialization() {
         adjacencylist = new Node*[total_vertices_]; // initialized the total pointers

        for (int i = 0; i < total_vertices_; i++) {
            adjacencylist[i] = nullptr; // set all the pointer to nullptr
        }
    }

    void addEdge(int current, int target) {
        Node* newNode = new Node(target); // create a new node with target's elementID
        newNode->setNext(adjacencylist[current]); // make newnode's next pointing to current node 
        adjacencylist[current] = newNode; //make new node as a new head 
    }

    bool checkEdge(int current, int target){
        Node* temp = adjacencylist[current]; //get the index which poining to head of the lists
        while (temp != nullptr) {
            if (temp->getID() == target) {// has edge
                return false; // return 1 if has edge
            }
            temp = temp->getNext(); // iterate through the lists
        }

        return true; // return 0 if no edge
        
    }

    int getTotalVertices() const {
        return total_vertices_;
    }

    void setTotalVertices(int v) {
        total_vertices_ = v;
    }

    Node** getAdjacencylist() {
        return this->adjacencylist;
    }

    private:
    int total_vertices_;
    Node** adjacencylist;
};