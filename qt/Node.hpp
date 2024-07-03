#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <algorithm>

template<typename T>
class Node {
private:
    T value;
    std::vector<Node<T> *> children;
    Node<T> *parent;  // Add parent pointer for traversal and drawing

public:
    Node(const T& val) : value(val), parent(nullptr) {}

    const T& get_value() const {
        return value;
    }

    void add_child(Node<T>* child) {
        children.push_back(child);
        child->parent = this;  // Set this node as the parent of the child
    }

    void remove_children() {
        children.clear();
    }

    const std::vector<Node<T> *> &get_children() const {
        return children;
    }

    Node<T> *get_parent() const {
        return parent;
    }

    bool is_leaf() const {
        return children.empty();
    }

    // Additional methods you may need for drawing and traversal
    // Example: Methods to compute or set positions for drawing
    // These methods will depend on your specific visualization needs.
    // For example, you may compute positions based on depth, etc.
};
#endif