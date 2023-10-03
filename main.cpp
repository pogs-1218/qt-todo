#include "todo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Todo w;
    w.show();
    w.setWindowTitle(QApplication::translate("toplevel", "TODO Application"));
    return a.exec();
}
