// cohen.shirel098@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include "TreeIterators.hpp"
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

template<typename T>
class Node;

// Tree class template with default K=2
template<typename T, int K = 2>
class Tree {
private:
    Node<T>* root; // Pointer to the root node of the tree

public:
    // Constructor initializes with a null root
    Tree() : root(nullptr) {}

    // Getter for the root node
    Node<T>* get_root() const {
        return root;
    }

    // Setter to add a new root node
    void add_root(Node<T>* root) {
        this->root = root;
    }

    // Overloaded output operator to print the tree in-order
    friend std::ostream& operator<<(std::ostream& os, const Tree& tree) {
        // This is a simple example, you may want to customize it
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            os << it->get_value() << " ";
        }
        return os;
    }

    // Method to add a child node to a parent node
    void add_sub_node(Node<T>* parent, Node<T>* child) {
        if (parent->get_children().size() >= K) {
            throw std::runtime_error("too much chuldren");
        }
        parent->add_child(child);
    }

    // Begin and end methods for Pre-Order traversal
    PreOrderIterable<T, K> begin_pre_order() const {
        return PreOrderIterable<T, K>(this->root);
    }
    PreOrderIterable<T, K> end_pre_order() const {
        return PreOrderIterable<T, K>(nullptr);
    }

    // Begin and end methods for Post-Order traversal
    PostOrderIterable<T, K> begin_post_order() const {
        return PostOrderIterable<T, K>(this->root);
    }
    PostOrderIterable<T, K> end_post_order() const {
        return PostOrderIterable<T, K>(nullptr);
    }

    // Begin and end methods for In-Order traversal
    InOrderIterable<T, K> begin_in_order() const {
        return InOrderIterable<T, K>(this->root);
    }
    InOrderIterable<T, K> end_in_order() const {
        return InOrderIterable<T, K>(nullptr);
    }

    // Begin method for Breadth-First Search (BFS) traversal
    BFSIterable<T, K> begin_bfs_scan() {
        return BFSIterable<T, K>(root);
    }

    // Begin method for Depth-First Search (DFS) traversal
    DFSIterable<T, K> begin_dfs_scan() {
        return DFSIterable<T, K>(root);
    }

    // End methods for BFS and DFS traversal
    BFSIterable<T, K> end_bfs_scan() {
        return BFSIterable<T, K>(nullptr);
    }
    DFSIterable<T, K> end_dfs_scan() {
        return DFSIterable<T, K>(nullptr);
    }

    // Method to create a Min-Heap iterator
    MinHeapIterator<T> myHeap() {
        return MinHeapIterator<T>(root);
    }

    // Begin and end methods for iteration (assumed BFS for simplicity)
    BFSIterable<T, K> begin() {
        return begin_bfs_scan();
    }
    BFSIterable<T, K> end() {
        return end_bfs_scan();
    }

};

#endif // TREE_HPP
// cohen.shirel098@gmail.com
