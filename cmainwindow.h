#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();
};
#endif // CMAINWINDOW_H
