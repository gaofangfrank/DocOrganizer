#pragma once

#include <QMainWindow>

class QTabBar;
class QGridLayout;
class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *Parent = nullptr);
  ~MainWindow();

private:
  QList<QWidget *> AllocatedWidgets;

  template <typename T, typename... ArgTy> T *create(ArgTy... Args) {
    auto *RetVal = new T(Args...);
    AllocatedWidgets.push_back(RetVal);
    return RetVal;
  }
};

