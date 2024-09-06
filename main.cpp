#include "cmainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMainWindow w;
    // w.show();

    CLoginWid l;
    l.show();

    CRegisterWid r;
    r.show();

    return a.exec();
}
