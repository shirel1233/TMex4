#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Tree.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void drawTree();
    void drawNode(Node<double>* node, int x, int y, int radius, int h_gap, int v_gap, int level);
    void drawConnections(Node<double>* node, int x, int y, int radius, int h_gap, int v_gap, int level);

    Tree<double, 2> tree;
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // MAINWINDOW_H
