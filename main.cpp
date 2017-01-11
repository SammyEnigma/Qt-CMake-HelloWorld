#include "mainwindow.h"
#include <QApplication>

#if defined(QT_STATIC) && defined(WIN32)
# include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
