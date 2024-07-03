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
template<typename T, int K =2>
class Tree {
private:
    Node<T>* root;

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        //delete_tree(root);
    }
    Node<T>* get_root() const {
        return root;
    }

    void add_root(Node<T>* root) {
        this->root = root;
    }

    void add_sub_node(Node<T>* parent, Node<T>* child) {
        if (parent->get_children().size() >= K) {
            throw std::runtime_error("Parent already has " + std::to_string(K) + " children, can't add more.");
        }
        parent->add_child(child);
    }

    // Iterator methods for traversal
    PreOrderIterable<T,K> begin_pre_order() const {
        return PreOrderIterable<T, K>(this->root);
    }
    PreOrderIterable<T, K> end_pre_order() const {
        return PreOrderIterable<T, K>(nullptr);
    }

    PostOrderIterable<T,K> begin_post_order() const {
        return PostOrderIterable<T, K>(this->root);
    }
    PostOrderIterable<T,K> end_post_order() const {
        return PostOrderIterable<T, K>(nullptr);
    }

    InOrderIterable<T, K> begin_in_order() const {
        return InOrderIterable<T, K>(this->root);
    }
    InOrderIterable<T, K> end_in_order() const {
        return InOrderIterable<T, K>(nullptr);
    }

    BFSIterable<T, K> begin_bfs_scan() const {
        return BFSIterable<T, K>(this->root);
    }
    BFSIterable<T, K> end_bfs_scan() const {
        return BFSIterable<T, K>(nullptr);
    }

    DFSIterable<T, K> begin_dfs_scan() const {
        return DFSIterable<T, K>(this->root);
    }
    DFSIterable<T, K> end_dfs_scan() const {
        return DFSIterable<T, K>(nullptr);
    }

    // Function to delete the entire tree
    void delete_tree(Node<T>* node) {
        if (node) {
            for (auto child : node->get_children()) {
                delete_tree(child);
            }
            delete node;
        }
    }

    // Function to draw the tree using Qt
    void draw(QPainter &painter) const {
        if (root) {
            draw_recursive(painter, root, nullptr, 400, 40, 200);
        }
    }

private:
    // Recursive function to draw nodes and edges
    void draw_recursive(QPainter &painter, Node<T>* node, Node<T>* parent, int x, int y, int spacing) const {
        // Draw node
        painter.drawEllipse(x, y, 30, 30);
        painter.drawText(x + 10, y + 20, QString::number(node->get_value())); // Example: Draw value as text

        // Draw edge to parent (if parent exists)
        if (parent) {
            painter.drawLine(x + 15, y, x + 15, y - 20);
            painter.drawLine(x + 15, y - 20, x + spacing, y - 20);
            painter.drawLine(x + spacing, y - 20, x + spacing, y - 10);
        }

        // Calculate next positions for children
        int num_children = node->get_children().size();
        int new_spacing = spacing / num_children;
        int new_x = x - spacing / 2;

        // Recursively draw children
        int i = 0;
        for (auto child : node->get_children()) {
            int new_y = y + 100; // Example: Increment y for vertical layout
            draw_recursive(painter, child, node, new_x + i * new_spacing, new_y, new_spacing);
            ++i;
        }
    }
};

#endif // TREE_HPP
