#include "addtododialog.h"
#include "ui_addtododialog.h"

AddTodoDialog::AddTodoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTodoDialog)
{
    ui->setupUi(this);
}

AddTodoDialog::~AddTodoDialog()
{
    delete ui;
}
