// cohen.shirel098@gmail.com

#ifndef TREEITERATORS_HPP
#define TREEITERATORS_HPP

#include <vector>
#include "Tree.hpp" // Include the Tree class and Node class
#include <stack>
#include <iostream> // For std::cout, std::endl
#include <queue>
#include <functional> // For std::function


template<typename T, int K>
class DFSIterable {
private:
    std::stack<Node<T>*> nodeStack; // Stack to hold nodes for DFS traversal

public:
    // Constructor initializes DFS with the root node
    DFSIterable(Node<T>* root) {
        if (root) nodeStack.push(root);
    }

    // Inequality operator for comparison
    bool operator!=(const DFSIterable& other) const {
        return !(*this == other);
    }

    // Equality operator for comparison
    bool operator==(const DFSIterable& other) const {
        if (nodeStack.empty() && other.nodeStack.empty()) return true;
        if (nodeStack.empty() || other.nodeStack.empty()) return false;
        return nodeStack.top() == other.nodeStack.top();
    }

    // Dereference operator to access the current node
    Node<T>* operator*() const {
        return nodeStack.top();
    }

    // Arrow operator to access the current node
    Node<T>* operator->() const {
        return nodeStack.top();
    }

    // Pre-increment operator to move to the next node in DFS
    DFSIterable& operator++() {
        Node<T>* node = nodeStack.top();
        nodeStack.pop();
        auto& children = node->get_children();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            nodeStack.push(*it);
        }
        return *this;
    }
};


// General case for when K != 2
template<typename T, int K>
class PreOrderIterable : public DFSIterable<T, K> {
public:
    // Constructor inherits from DFSIterable
    PreOrderIterable(Node<T>* root) : DFSIterable<T, K>(root) {}
    // No need to override operators since they are inherited and already handle DFS iteration
};

template<typename T, int K>
class InOrderIterable : public DFSIterable<T, K> {
public:
    // Constructor inherits from DFSIterable
    InOrderIterable(Node<T>* root) : DFSIterable<T, K>(root) {}
    // No need to override operators since they are inherited and already handle DFS iteration
};

template<typename T, int K>
class PostOrderIterable : public DFSIterable<T, K> {
public:
    // Constructor inherits from DFSIterable
    PostOrderIterable(Node<T>* root) : DFSIterable<T, K>(root) {}
    // No need to override operators since they are inherited and already handle DFS iteration
};


// Specialized InOrderIterable for K = 2 (binary trees)
template<typename T>
class InOrderIterable<T, 2> {
public:
    // Constructor initializes InOrder traversal with the leftmost nodes
    InOrderIterable(Node<T>* root) {
        if(root){
            push_leftmost_nodes(root);
        }
    }

    // Arrow operator to access the current node
    Node<T>* operator->() const {
        return traversal.top();
    }

    // Dereference operator to access the value of the current node
    T& operator*() {
        return traversal.top()->get_value();
    }

    // Inequality operator for comparison
    bool operator!=(const InOrderIterable& other) const {
        if (traversal.empty() && other.traversal.empty()) {
            return false;
        }
        if (traversal.empty() || other.traversal.empty()) {
            return true;
        }
        return traversal.top() != other.traversal.top();
    }

    // Equality operator for comparison
    bool operator==(const InOrderIterable& other) const {
        return !(*this != other);
    }

    // Pre-increment operator to move to the next node in InOrder
    InOrderIterable& operator++() {
        Node<T>* node = traversal.top();
        traversal.pop();
        // Move to the right child if available
        if (!node->get_children().empty() && node->get_children().size() > 1) {
            push_leftmost_nodes(node->get_children()[1]);
        }
        return *this;
    }

private:
    std::stack<Node<T>*> traversal; // Stack to hold nodes for InOrder traversal

    // Helper function to push leftmost nodes onto the stack
    void push_leftmost_nodes(Node<T>* node) {
        while (node) {
            traversal.push(node);
            if (!node->get_children().empty()) {
                node = node->get_children()[0];
            } else {
                node = nullptr;
            }
        }
    }
};

template<typename T>
class PreOrderIterable<T, 2> {
public:
    // Constructor initializes PreOrder traversal with the root node
    PreOrderIterable(Node<T>* root) {
        if (root) {
            traversal.push(root);
        }
    }

    // Arrow operator to access the current node
    Node<T>* operator->() const {
        return traversal.top();
    }

    // Dereference operator to access the value of the current node
    T& operator*() {
        return traversal.top()->get_value();
    }

    // Inequality operator for comparison
    bool operator!=(const PreOrderIterable& other) const {
        if (traversal.empty() && other.traversal.empty()) {
            return false;
        }
        if (traversal.empty() || other.traversal.empty()) {
            return true;
        }
        return traversal.top() != other.traversal.top();
    }

    // Equality operator for comparison
    bool operator==(const PreOrderIterable& other) const {
        return !(*this != other);
    }

    // Pre-increment operator to move to the next node in PreOrder
    PreOrderIterable& operator++() {
        Node<T>* node = traversal.top();
        traversal.pop();
        // Push children in reverse order to maintain PreOrder (root, left, right)
        for (auto it = node->get_children().rbegin(); it != node->get_children().rend(); ++it) {
            traversal.push(*it);
        }
        return *this;
    }

private:
    std::stack<Node<T>*> traversal; // Stack to hold nodes for PreOrder traversal
};


template<typename T>
class PostOrderIterable<T, 2> {
public:
    // Constructor initializes PostOrder traversal with the root node
    PostOrderIterable(Node<T>* root) {
        if (root) {
            push_post_order_nodes(root);
        }
    }

    // Arrow operator to access the current node
    Node<T>* operator->() const {
        return traversal.top();
    }

    // Dereference operator to access the value of the current node
    T& operator*() {
        return traversal.top()->get_value();
    }

    // Inequality operator for comparison
    bool operator!=(const PostOrderIterable& other) const {
        if (traversal.empty() && other.traversal.empty()) {
            return false;
        }
        if (traversal.empty() || other.traversal.empty()) {
            return true;
        }
        return traversal.top() != other.traversal.top();
    }

    // Equality operator for comparison
    bool operator==(const PostOrderIterable& other) const {
        return !(*this != other);
    }

    // Pre-increment operator to move to the next node in PostOrder
    PostOrderIterable& operator++() {
        traversal.pop();
        return *this;
    }

private:
    std::stack<Node<T>*> traversal; // Stack to hold nodes for PostOrder traversal

    // Helper function to push nodes in PostOrder sequence onto the stack
    void push_post_order_nodes(Node<T>* node) {
        std::stack<Node<T>*> temp_stack;
        temp_stack.push(node);
        while (!temp_stack.empty()) {
            Node<T>* current = temp_stack.top();
            temp_stack.pop();
            traversal.push(current);
            // Push children in the order: right, left, root (for PostOrder)
            for (auto child : current->get_children()) {
                temp_stack.push(child);
            }
        }
    }
};


template<typename T, int K>
class BFSIterable {
public:
    // Constructor initializes BFS traversal with the root node
    BFSIterable(Node<T>* root) {
        if(root == nullptr){
            return;
        }
        q.push(root);
    }

    // Pre-increment operator to move to the next node in BFS
    BFSIterable& operator++() {
        if (!q.empty()) {
            Node<T>* node = q.front();
            q.pop();
            auto children = node->get_children();
            for (size_t i = 0; i < children.size(); ++i) {
                Node<T>* child = children.at(i);
                if (child != nullptr) {  // Check if child is valid before pushing into queue
                    q.push(child);
                }
            }
        }
        return *this;
    }

    // Arrow operator to access the current node
    Node<T>* operator->() const {
        return q.front();
    }

    // Dereference operator to access the value of the current node
    const T& operator*() {
        return q.front()->get_value();
    }

    // Equality operator for comparison
    bool operator==(const BFSIterable& other) const { return q.size() == other.q.size(); }

    // Inequality operator for comparison
    bool operator!=(const BFSIterable& other) const {
        return !((*this) == other); // Negate the result of the equality operator
    }

private:
    std::queue<Node<T>*> q; // Queue to hold nodes for BFS traversal
};

template<typename T>
class MinHeapIterator {
private:
    std::vector<Node<T>*> heap;
    size_t index;

    // Helper function to heapify the tree starting from the root
    void heapify(Node<T>* root) {
        if (!root) return;
        // Priority queue to maintain min-heap property based on node values
        std::priority_queue<Node<T>*, std::vector<Node<T>*>, std::function<bool(Node<T>*, Node<T>*)>> pq(
            [](Node<T>* a, Node<T>* b) 
            { return a->get_value() > b->get_value(); } // Lambda function to define comparison
        );

        pq.push(root);
        while (!pq.empty()) {
            Node<T>* current = pq.top();
            pq.pop();
            heap.push_back(current);
            for (Node<T>* child : current->get_children()) {
                pq.push(child);
            }
        }
    }

public:
    // Constructor initializes the min-heap iterator with the root node
    MinHeapIterator(Node<T>* root) : index(0) {
        heapify(root);
    }

    // Function to retrieve the next node in the heap
    Node<T>* next() {
        if (index < heap.size()) {
            return heap[index++];
        }
        return nullptr;
    }

    // Function to check if there are more nodes in the heap
    bool has_next() const {
        return index < heap.size();
    }

};

#endif // TREEITERATORS_HPP
