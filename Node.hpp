// cohen.shirel098@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <algorithm>

template<typename T>
class Node {
private:
    T value; // Value stored in the node
    std::vector<Node<T> *> children; // Vector to store pointers to child nodes

public:
    // Constructor to initialize with a value
    Node(const T& val) : value(val) {}

    // Getter for retrieving the node's value
    const T& get_value() const {
        return value;
    }

    // Method to add a child node
    void add_child(Node<T>* child) {
        children.push_back(child);
    }

    // Method to remove all children nodes
    void remove_children() {
        children.clear();
    }

    // Getter to retrieve the vector of child nodes
    const std::vector<Node<T> *> &get_children() const { 
        return children; 
    }

};

#endif // NODE_HPP
// cohen.shirel098@gmail.com
