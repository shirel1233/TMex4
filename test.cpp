// cohen.shirel098@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"
#include "TreeIterators.hpp"
#include "Complex.hpp"

// Binary Tree Test Cases
TEST_CASE("Binary Tree Traversal Tests") {
    // Set up a complex binary tree
    Node<double> root_node(10.1);
    Tree<double> tree;
    tree.add_root(&root_node);
    Node<double> n1(20.2);
    Node<double> n2(30.3);
    Node<double> n3(40.4);
    Node<double> n4(50.5);
    Node<double> n5(60.6);
    Node<double> n6(70.7);
    Node<double> n7(80.8);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);
    tree.add_sub_node(&n5, &n6);
    tree.add_sub_node(&n5, &n7);

    SUBCASE("Pre-order traversal") {
        std::vector<double> expected = {10.1, 20.2, 40.4, 50.5, 30.3, 60.6, 70.7, 80.8};
        std::vector<double> result;

        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("Post-order traversal") {
        std::vector<double> expected = {40.4, 50.5, 20.2, 70.7, 80.8, 60.6, 30.3, 10.1};
        std::vector<double> result;

        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("In-order traversal") {
        std::vector<double> expected = {40.4, 20.2, 50.5, 10.1, 70.7, 60.6, 80.8, 30.3};
        std::vector<double> result;

        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("BFS traversal") {
        std::vector<double> expected = {10.1, 20.2, 30.3, 40.4, 50.5, 60.6, 70.7, 80.8};
        std::vector<double> result;

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
            result.push_back(node->get_value());
            //std::cout<<node->get_value()<<std::endl;
    
        }
        

        CHECK(result == expected);
    }

    SUBCASE("DFS traversal") {
        std::vector<double> expected = {10.1, 20.2, 40.4 ,50.5 ,30.3, 60.6, 70.7, 80.8};
        std::vector<double> result;

        //10.1, 20.2, 40.4, 50.5, 30.3, 60.6, 70.7, 80.8

        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("Heap traversal") {
        std::vector<double> expected = {10.1, 20.2, 30.3, 40.4, 50.5, 60.6, 70.7, 80.8};
        std::vector<double> result;

        MinHeapIterator<double> it = tree.myHeap();
        while (it.has_next()) {
            result.push_back(it.next()->get_value());
        }

        CHECK(result == expected);
    }
}

// Ternary Tree Test Cases
TEST_CASE("Ternary Tree Traversal Tests") {
    // Set up a ternary tree
    Node<double> ternary_root(1.1);
    Tree<double, 3> ternary_tree;
    ternary_tree.add_root(&ternary_root);
    Node<double> t1(2.2);
    Node<double> t2(3.3);
    Node<double> t3(4.4);
    Node<double> t4(5.5);
    Node<double> t5(6.6);
    Node<double> t6(7.7);

    ternary_tree.add_sub_node(&ternary_root, &t1);
    ternary_tree.add_sub_node(&ternary_root, &t2);
    ternary_tree.add_sub_node(&ternary_root, &t3);
    ternary_tree.add_sub_node(&t1, &t4);
    ternary_tree.add_sub_node(&t1, &t5);
    ternary_tree.add_sub_node(&t3, &t6);

    SUBCASE("Pre-order traversal") {
        std::vector<double> expected = {1.1, 2.2, 5.5, 6.6, 3.3, 4.4, 7.7};
        std::vector<double> result;

        for (auto node = ternary_tree.begin_pre_order(); node != ternary_tree.end_pre_order(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("In-order traversal") {
        std::vector<double> expected = {1.1, 2.2, 5.5, 6.6, 3.3, 4.4, 7.7};
        std::vector<double> result;
        for (auto node = ternary_tree.begin_in_order(); node != ternary_tree.end_in_order(); ++node) {
            result.push_back(node->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("Post-order traversal") {
        std::vector<double> expected = {1.1, 2.2, 5.5, 6.6, 3.3, 4.4, 7.7};
        std::vector<double> result;

        for (auto node = ternary_tree.begin_post_order(); node != ternary_tree.end_post_order(); ++node) {
            result.push_back(node->get_value());
        }
        CHECK(result == expected);
    }


    SUBCASE("BFS traversal") {
        std::vector<double> expected = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
        std::vector<double> result;

        for (auto node = ternary_tree.begin_bfs_scan(); node != ternary_tree.end_bfs_scan(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("DFS traversal") {
        std::vector<double> expected = {1.1, 2.2, 5.5, 6.6, 3.3, 4.4, 7.7};
        std::vector<double> result;
        //1.1, 2.2, 5.5, 6.6, 3.3, 4.4, 7.7

        for (auto node = ternary_tree.begin_dfs_scan(); node != ternary_tree.end_dfs_scan(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }
}

// Empty Tree Test Cases
TEST_CASE("Empty Tree Traversal Tests") {
    // Set up an empty tree
    Tree<double> empty_tree;

    SUBCASE("Pre-order traversal") {
        std::vector<double> expected = {};
        std::vector<double> result;

        for (auto node = empty_tree.begin_pre_order(); node != empty_tree.end_pre_order(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("BFS traversal") {
        std::vector<double> expected = {};
        std::vector<double> result;

        for (auto node = empty_tree.begin_bfs_scan(); node != empty_tree.end_bfs_scan(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }
}


// Binary Tree Test Cases
TEST_CASE("Complex Binary Tree Traversal Tests") {
    // Set up a complex binary tree
    Node<Complex> root_node(Complex(10.1, 20.2));
    Tree<Complex> tree;
    tree.add_root(&root_node);

    Node<Complex> n1(Complex(30.3, 40.4));
    Node<Complex> n2(Complex(50.5, 60.6));
    Node<Complex> n3(Complex(70.7, 80.8));
    Node<Complex> n4(Complex(90.9, 100.1));
    Node<Complex> n5(Complex(110.11, 120.12));
    Node<Complex> n6(Complex(130.13, 140.14));

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);
    tree.add_sub_node(&n5, &n6);

    SUBCASE("Pre-order traversal") {
        std::vector<Complex> expected = {Complex(10.1, 20.2), Complex(30.3, 40.4), Complex(70.7, 80.8),
                                         Complex(90.9, 100.1), Complex(50.5, 60.6), Complex(110.11, 120.12),
                                         Complex(130.13, 140.14)};
        std::vector<Complex> result;

        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
            result.push_back(node->get_value());
            

        }

        CHECK(result == expected);
    }

    SUBCASE("Post-order traversal") {
        std::vector<Complex> expected = {Complex(70.7, 80.8), Complex(90.9, 100.1), Complex(30.3, 40.4),
                                         Complex(130.13, 140.14), Complex(110.11, 120.12), Complex(50.5, 60.6),
                                         Complex(10.1, 20.2)};
        std::vector<Complex> result;

        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("In-order traversal") {
        std::vector<Complex> expected = {Complex(70.7, 80.8), Complex(30.3, 40.4), Complex(90.9, 100.1),
                                         Complex(10.1, 20.2), Complex(130.13, 140.14), Complex(110.11,120.12),
                                         Complex(50.5, 60.6)};
        std::vector<Complex> result;
        

        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("BFS traversal") {
        std::vector<Complex> expected = {Complex(10.1, 20.2), Complex(30.3, 40.4), Complex(50.5, 60.6),
                                         Complex(70.7, 80.8), Complex(90.9, 100.1), Complex(110.11, 120.12),
                                         Complex(130.13, 140.14)};
        std::vector<Complex> result;

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("DFS traversal") {
        std::vector<Complex> expected = {Complex(10.1, 20.2), Complex(30.3, 40.4), Complex(70.7, 80.8),
                                         Complex(90.9, 100.1), Complex(50.5, 60.6), Complex(110.11, 120.12),
                                         Complex(130.13, 140.14)};
        std::vector<Complex> result; 


        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
            result.push_back(node->get_value());
            
        }

        CHECK(result == expected);
    }

}

// Ternary Tree Test Cases
TEST_CASE("Complex Ternary Tree Traversal Tests") {
    // Set up a complex ternary tree
    Node<Complex> ternary_root(Complex(1.1, 2.2));
    Tree<Complex, 3> ternary_tree;
    ternary_tree.add_root(&ternary_root);

    Node<Complex> t1(Complex(3.3, 4.4));
    Node<Complex> t2(Complex(5.5, 6.6));
    Node<Complex> t3(Complex(7.7, 8.8));
    Node<Complex> t4(Complex(9.9, 10.1));
    Node<Complex> t5(Complex(11.11, 12.12));
    Node<Complex> t6(Complex(13.13, 14.14));

    ternary_tree.add_sub_node(&ternary_root, &t1);
    ternary_tree.add_sub_node(&ternary_root, &t2);
    ternary_tree.add_sub_node(&ternary_root, &t3);
    ternary_tree.add_sub_node(&t1, &t4);
    ternary_tree.add_sub_node(&t1, &t5);
    ternary_tree.add_sub_node(&t3, &t6);

    SUBCASE("Pre-order traversal") {
        std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(9.9, 10.1),
                                         Complex(11.11, 12.12), Complex(5.5, 6.6), Complex(7.7, 8.8),
                                         Complex(13.13, 14.14)};
        std::vector<Complex> result;

        for (auto node = ternary_tree.begin_pre_order(); node != ternary_tree.end_pre_order(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("In-order traversal") {
        std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(9.9, 10.1),
                                         Complex(11.11, 12.12), Complex(5.5, 6.6), Complex(7.7, 8.8),
                                         Complex(13.13, 14.14)};
        std::vector<Complex> result;

        for (auto node = ternary_tree.begin_in_order(); node != ternary_tree.end_in_order(); ++node) {
            result.push_back(node->get_value());
            //std::cout<<node->get_value()<<std::endl;
        }

        CHECK(result == expected);
    }

    SUBCASE("Post-order traversal") {
        std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(9.9, 10.1),
                                         Complex(11.11, 12.12), Complex(5.5, 6.6), Complex(7.7, 8.8),
                                         Complex(13.13, 14.14)};
        std::vector<Complex> result;

        for (auto node = ternary_tree.begin_post_order(); node != ternary_tree.end_post_order(); ++node) {
            result.push_back(node->get_value());
            //std::cout<<node->get_value()<<std::endl;
        }

        CHECK(result == expected);
    }

    SUBCASE("BFS traversal") {
        std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(5.5, 6.6),
                                         Complex(7.7, 8.8), Complex(9.9, 10.1), Complex(11.11, 12.12),
                                         Complex(13.13, 14.14)};
        std::vector<Complex> result;

        for (auto node = ternary_tree.begin_bfs_scan(); node != ternary_tree.end_bfs_scan(); ++node) {
            result.push_back(node->get_value());
            //std::cout<<node->get_value()<<std::endl;
        }

        CHECK(result == expected);
    }

    SUBCASE("DFS traversal") {
        std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(9.9, 10.1),
                                         Complex(11.11, 12.12), Complex(5.5, 6.6), Complex(7.7, 8.8),
                                         Complex(13.13, 14.14)};
        std::vector<Complex> result;

        for (auto node = ternary_tree.begin_dfs_scan(); node != ternary_tree.end_dfs_scan(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }
}

// Empty Tree Test Cases
TEST_CASE("Empty Complex Tree Traversal Tests") {
    // Set up an empty complex tree
    Tree<Complex> empty_tree;

    SUBCASE("Pre-order traversal") {
        std::vector<Complex> expected = {};
        std::vector<Complex> result;

        for (auto node = empty_tree.begin_pre_order(); node != empty_tree.end_pre_order(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("BFS traversal") {
        std::vector<Complex> expected = {};
        std::vector<Complex> result;

        for (auto node = empty_tree.begin_bfs_scan(); node != empty_tree.end_bfs_scan(); ++node) {
            result.push_back(node->get_value());
        }

        CHECK(result == expected);
    }
}