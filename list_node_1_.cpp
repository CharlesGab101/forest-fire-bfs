class Node {
public:
    Node(int id)
        : elementID_(id), next(nullptr) {}

    int getID() const {
        return elementID_;
    }

    void setID(int elementID) {
        elementID_ = elementID;
    }

    Node* getNext() const {
        return next;
    }

    void setNext(Node* n) {
        next = n;
    }

private:
    int elementID_;
    Node* next;
};
