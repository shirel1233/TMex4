#ifndef TREEITERATORS_HPP
#define TREEITERATORS_HPP

#include <vector>
#include "Tree.hpp"
#include <stack>
#include <iostream> 
#include <queue>
#include <functional>

template<typename T, int K>
class DFSIterable;

template<typename T, int K>
class PreOrderIterable : public DFSIterable<T, K> {
public:
    using typename DFSIterable<T, K>::iterator;

    PreOrderIterable(Node<T>* root) : DFSIterable<T, K>(root) {
        static_assert(K != 2, "PreOrderIterable does not support K = 2");
    }

    // No need to override operators since they are inherited and already handle DFS iteration
};


template<typename T, int K>
class InOrderIterable : public DFSIterable<T, K> {
public:
    using typename DFSIterable<T, K>::iterator;

    InOrderIterable(Node<T>* root) : DFSIterable<T, K>(root) {
        static_assert(K != 2, "InOrderIterableBase does not support K = 2");
    }

    // No need to override operators since they are inherited and already handle DFS iteration
};
template<typename T, int K>
class PostOrderIterable : public DFSIterable<T, K> {
public:
    using typename DFSIterable<T, K>::iterator;

    PostOrderIterable(Node<T>* root) : DFSIterable<T, K>(root) {
        static_assert(K != 2, "PostOrderIterableBase does not support K = 2");
    }

    // No need to override operators since they are inherited and already handle DFS iteration
};



// Specialized InOrderIterable for K = 2 (binary trees)
template<typename T>
class InOrderIterable<T, 2> {
public:
   
    InOrderIterable(Node<T>* root) {
        if(root){
            push_leftmost_nodes(root);
        }
    }

    Node<T>* operator->() const {
        return traversal.top();
    }

    
    T& operator*() {
        return traversal.top().get_value();
    }

    bool operator!=(const InOrderIterable& other) const {
        if (traversal.empty() && other.traversal.empty()) {
            return false;
        }
        if (traversal.empty() || other.traversal.empty()) {
            return true;
        }
        return traversal.top() != other.traversal.top();
    }

    bool operator==(const InOrderIterable& other) const {
        return !(*this != other);
    }
    

    InOrderIterable& operator++() {
        Node<T>* node = traversal.top();
        traversal.pop();
        if (!node->get_children().empty() && node->get_children().size() > 1) {
            push_leftmost_nodes(node->get_children()[1]);
        }
        return *this;
    }

private:
    
    std::stack<Node<T>*> traversal;
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
    //using iterator = typename std::stack<Node<T>*>::iterator;

    PreOrderIterable(Node<T>* root) {
        if (root) {
            traversal.push(root);
        }
    }

    Node<T>* operator->() const {
        return traversal.top();
    }

    T& operator*() {
        return traversal.top()->get_value();
    }

    bool operator!=(const PreOrderIterable& other) const {
        if (traversal.empty() && other.traversal.empty()) {
            return false;
        }
        if (traversal.empty() || other.traversal.empty()) {
            return true;
        }
        return traversal.top() != other.traversal.top();
    }

    bool operator==(const PreOrderIterable& other) const {
        return !(*this != other);
    }

    PreOrderIterable& operator++() {
        Node<T>* node = traversal.top();
        traversal.pop();
        // Push children in reverse order to maintain pre-order (root, left, right)
        for (auto it = node->get_children().rbegin(); it != node->get_children().rend(); ++it) {
            traversal.push(*it);
        }
        return *this;
    }

private:
    std::stack<Node<T>*> traversal;
};


template<typename T>
class PostOrderIterable<T, 2> {
public:
    //using iterator = typename std::stack<Node<T>*>::iterator;

    PostOrderIterable(Node<T>* root) {
        if (root) {
            push_post_order_nodes(root);
        }
    }

    Node<T>* operator->() const {
        return traversal.top();
    }

    T& operator*() {
        return traversal.top()->get_value();
    }

    bool operator!=(const PostOrderIterable& other) const {
        if (traversal.empty() && other.traversal.empty()) {
            return false;
        }
        if (traversal.empty() || other.traversal.empty()) {
            return true;
        }
        return traversal.top() != other.traversal.top();
    }

    bool operator==(const PostOrderIterable& other) const {
        return !(*this != other);
    }

    PostOrderIterable& operator++() {
        traversal.pop();
        return *this;
    }

private:
    std::stack<Node<T>*> traversal;

    void push_post_order_nodes(Node<T>* node) {
        std::stack<Node<T>*> temp_stack;
        temp_stack.push(node);
        while (!temp_stack.empty()) {
            Node<T>* current = temp_stack.top();
            temp_stack.pop();
            traversal.push(current);
            // Push children in the order: right, left, root (for post-order)
            for (auto child : current->get_children()) {
                temp_stack.push(child);
            }
        }
    }
};


template<typename T, int K>
class BFSIterable {
public:
    using iterator = typename std::vector<Node<T>*>::iterator;

    BFSIterable(Node<T>* root) {
        if(root==nullptr){
            return;
        }
            bfs_traversal(root);
            current = nodes.begin();
    }

    iterator begin() {
        return nodes.begin();
    }

    iterator end() {
        return nodes.end();
    }

    BFSIterable& operator++() {
        ++current;
        return *this;
    }

    Node<T>* operator->() const {
        return *current;
    }

    const T& operator*() {
        return (*current)->get_value();
    }

    bool operator!=(const BFSIterable& other) const {
        return current != other.current;
    }

    bool operator==(const BFSIterable& other) const {
        return current == other.current;
    }

private:
    std::vector<Node<T>*> nodes;
    iterator current;

    void bfs_traversal(Node<T>* root) {
    std::queue<Node<T>*> q;
    q.push(root);

    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        nodes.push_back(current);

        // Debug output: Print the value of the current node
        std::cout << "Adding node: " << current->get_value() << std::endl;

        // Traverse children and enqueue them for BFS
        for (auto child : current->get_children()) {
            q.push(child);
        }
    }
    }
};


template<typename T, int K>
class DFSIterable {
public:
    //using iterator = typename std::stack<Node<T>*>::iterator;

    DFSIterable(Node<T>* root) {
        if (root) {
            traversal.push(root);
        }
    }


    Node<T>* operator->() const {
        return traversal.top();
    }

    T& operator*() {
        return traversal.top()->get_value();
    }

    bool operator!=(const DFSIterable& other) const {
        if (traversal.empty() && other.traversal.empty()) {
            return false;
        }
        if (traversal.empty() || other.traversal.empty()) {
            return true;
        }
        return traversal.top() != other.traversal.top();
    }

    bool operator==(const DFSIterable& other) const {
        return !(*this != other);
    }

    DFSIterable& operator++() {
        Node<T>* node = traversal.top();
        traversal.pop();
        // Example: Push children in reverse order to maintain pre-order (root, left, right)
        for (auto it = node->get_children().rbegin(); it != node->get_children().rend(); ++it) {
            traversal.push(*it);
        }
        return *this;
    }

protected:
    std::stack<Node<T>*> traversal;
};

template<typename T>
class MinHeapIterator {
private:
    std::vector<Node<T>*> heap;
    size_t index;

    void heapify(Node<T>* root) {
        if (!root) return;
        std::priority_queue<Node<T>*, std::vector<Node<T>*>, std::function<bool(Node<T>*, Node<T>*)>> pq(
            [](Node<T>* a, Node<T>* b) { return a->get_value() > b->get_value(); }
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
    MinHeapIterator(Node<T>* root) : index(0) {
        heapify(root);
    }

    Node<T>* next() {
        if (index < heap.size()) {
            return heap[index++];
        }
        return nullptr;
    }

    bool has_next() const {
        return index < heap.size();
    }
};

#endif