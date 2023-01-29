#include "MainWindow.h"
#include <QDockWidget>
#include <QGridLayout>
#include <QStyleFactory>
#include <QTabBar>

// MainWindow definitions ======================================================
MainWindow::MainWindow(QWidget *Parent) : QMainWindow(Parent) {
  auto *CategoryTabBar = create<QTabBar>(this);
  // TODO: set the tab bar properly once we decide what we what to do with it
  for (auto key : QStyleFactory::keys()) {
    CategoryTabBar->addTab(key);
  }
  this->setCentralWidget(CategoryTabBar);
}

MainWindow::~MainWindow() {
  for (auto *W : AllocatedWidgets)
    delete W;
}
