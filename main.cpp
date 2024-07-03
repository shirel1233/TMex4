// cohen.shirel098@gmail.com
#include <iostream>
#include <string>
#include "Tree.hpp"
#include "Complex.hpp"


using namespace std;

int main() {
    
    // Creating nodes for the tree
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    // Creating a binary tree of doubles
    Tree<double, 2> tree;
    tree.add_root(&root_node);
    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    // Outputting the tree structure
    cout << "Binary Tree Structure:" << endl;
    cout << "       " << root_node.get_value() << endl;
    cout << "     /       \\" << endl;
    cout << "    " << n1.get_value() << "      " << n2.get_value() << endl;
    cout << "   /  \\      /" << endl;
    cout << "  " << n3.get_value() << "   " << n4.get_value() << "     " << n5.get_value() << endl;
    cout << endl;

    // Traversing the tree using different iterators
    
    cout << "Pre-order traversal:" << endl;
    for (auto node =tree.begin_pre_order(); node!=tree.end_pre_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "Post-order traversal:" << endl;
    for (auto node =tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "In-order traversal1:" << endl;
    for (auto node =tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;



    cout << "BFS traversal:" << endl;
    for (auto node =tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "DFS traversal:" << endl;
    for (auto node=tree.begin_dfs_scan(); node !=tree.end_dfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    // Creating nodes for a complex tree
    Node<Complex> root_complex_node(Complex(1.1, 2.2));
    Node<Complex> c1(Complex(1.2, 2.3));
    Node<Complex> c2(Complex(1.3, 2.4));
    Node<Complex> c3(Complex(1.4, 2.5));
    Node<Complex> c4(Complex(1.5, 2.6));
    Node<Complex> c5(Complex(1.6, 2.7));

    // Creating a binary tree of complex numbers
    Tree<Complex, 2> complex_tree;
    complex_tree.add_root(&root_complex_node);
    complex_tree.add_sub_node(&root_complex_node, &c1);
    complex_tree.add_sub_node(&root_complex_node, &c2);
    complex_tree.add_sub_node(&c1, &c3);
    complex_tree.add_sub_node(&c1, &c4);
    complex_tree.add_sub_node(&c2, &c5);

    // Outputting the complex tree structure
    cout << "Complex Tree Structure:" << endl;
    cout << "       " << root_complex_node.get_value() << endl;
    cout << "     /       \\" << endl;
    cout << "    " << c1.get_value() << "      " << c2.get_value() << endl;
    cout << "   /  \\      /" << endl;
    cout << "  " << c3.get_value() << "   " << c4.get_value() << "     " << c5.get_value() << endl;
    cout << endl;

    // Traversing the complex tree using different iterators
    cout << "Pre-order traversal (Complex):" << endl;
    for (auto node = complex_tree.begin_pre_order(); node != complex_tree.end_pre_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "Post-order traversal (Complex):" << endl;
    for (auto node = complex_tree.begin_post_order(); node != complex_tree.end_post_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "In-order traversal (Complex):" << endl;
    for (auto node = complex_tree.begin_in_order(); node != complex_tree.end_in_order(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "BFS traversal (Complex):" << endl;
    for (auto node = complex_tree.begin_bfs_scan(); node != complex_tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "DFS traversal (Complex):" << endl;
    for (auto node = complex_tree.begin_dfs_scan(); node != complex_tree.end_dfs_scan(); ++node) {
        cout << node->get_value() << " ";
    }
    cout << endl;


    return 0;
}
