#ifndef TODO_H
#define TODO_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "addtododialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Todo; }
QT_END_NAMESPACE

class Todo : public QMainWindow
{
    Q_OBJECT

public:
    Todo(QWidget *parent = nullptr);
    ~Todo();

private slots:
    void newClicked();
    void todoClicked(const QModelIndex &index);
    void doneClicked(const QModelIndex &index);

private:
    Ui::Todo *ui;

    QStandardItemModel todo_model;
    QStandardItemModel done_model;

    AddTodoDialog *add_dialog;

    void setSignals();
};

#endif // TODO_H
