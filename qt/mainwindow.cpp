#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QVBoxLayout>
#include <cmath>

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene(this)), view(new QGraphicsView(scene, this))
{
    ui->setupUi(this);
    setCentralWidget(view);
    resize(800, 600);

    // Set up the tree structure (assuming you have a Tree class with appropriate methods)
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_root(&root_node);
    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    // Draw the tree
    drawTree();
}

void MainWindow::drawTree()
{
    int x = width() / 2; // Start drawing from the middle of the view
    int y = 50; // Start drawing from near the top
    int level = 0; // Root level
    int radius = 20; // Radius for node circles
    int h_gap = 100; // Horizontal gap between nodes
    int v_gap = 80; // Vertical gap between levels

    // Draw nodes
    drawNode(tree.get_root(), x, y, radius, h_gap, v_gap, level);

    // Draw connections (lines between nodes)
    drawConnections(tree.get_root(), x, y, radius, h_gap, v_gap, level);
}

void MainWindow::drawNode(Node<double>* node, int x, int y, int radius, int h_gap, int v_gap, int level)
{
    if (node == nullptr) return;

    // Draw the node as a circle
    QGraphicsEllipseItem *item = scene->addEllipse(x - radius, y - radius, 2 * radius, 2 * radius);
    item->setFlag(QGraphicsItem::ItemIsMovable); // Example of adding interaction
    scene->addText(QString::number(node->get_value()))->setPos(x - 10, y - 10); // Example of adding text to the node

    // Draw children nodes
    auto children = node->get_children();
    int child_count = children.size();
    int child_x = x - (child_count - 1) * h_gap / 2;

    for (int i = 0; i < child_count; ++i) {
        drawNode(children[i], child_x + i * h_gap, y + v_gap, radius, h_gap / 2, v_gap, level + 1);
    }
}

void MainWindow::drawConnections(Node<double>* node, int x, int y, int radius, int h_gap, int v_gap, int level)
{
    if (node == nullptr || node->get_children().empty()) return;

    auto children = node->get_children();
    int child_count = children.size();
    int child_x = x - (child_count - 1) * h_gap / 2;

    for (int i = 0; i < child_count; ++i) {
        int child_center_x = child_x + i * h_gap;
        int child_center_y = y + v_gap;

        // Draw line
        QGraphicsLineItem *line = scene->addLine(x, y + radius, child_center_x, child_center_y - radius);
        line->setPen(QPen(Qt::black, 2)); // Example of setting line properties

        // Recursively draw connections for children
        drawConnections(children[i], child_center_x, child_center_y, radius, h_gap / 2, v_gap, level + 1);
    }
}
