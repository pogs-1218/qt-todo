#include "todo.h"
#include <QDate>
#include "./ui_todo.h"
#include "QtGui/qstandarditemmodel.h"
#include "addtododialog.h"

Todo::Todo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Todo)
    , add_dialog(nullptr)
{
    ui->setupUi(this);
    // TODO: Update daily, while the programmin is running.
    ui->todayDate->setText(QDate::currentDate().toString("MMM. d"));

    for (auto i = 0; i < 3; i++) {
        auto item = new QStandardItem(QString("item %0").arg(i));
        item->setCheckState(Qt::Unchecked);
        item->setCheckable(true);
        todo_model.appendRow(item);
    }

    ui->todoList->setModel(&todo_model);
    ui->doneList->setModel(&done_model);

    setSignals();
}

Todo::~Todo()
{
    delete ui;
}

void Todo::setSignals()
{
    connect(ui->todoList, &QListView::clicked, this, &Todo::todoClicked);
    connect(ui->doneList, &QListView::clicked, this, &Todo::doneClicked);
    connect(ui->newButton, &QPushButton::clicked, this, &Todo::newClicked);
}

void Todo::newClicked()
{
    add_dialog = new AddTodoDialog(this);
    add_dialog->show();
}

void Todo::todoClicked(const QModelIndex &index)
{
    auto item = todo_model.itemFromIndex(index);
    int isChecked = item->data(Qt::CheckStateRole).toInt();
    auto item_string = item->data(Qt::DisplayRole).toString();

    qDebug() << item_string;

    if (isChecked) {
        done_model.appendRow(new QStandardItem(item_string));
        delete item;
    }
}

void Todo::doneClicked(const QModelIndex &index) {}
