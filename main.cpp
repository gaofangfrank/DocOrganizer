#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication App(argc, argv);
  App.setStyle("Fusion");

  MainWindow Window;
  Window.show();

  return App.exec();
}
