#ifndef ADDTODODIALOG_H
#define ADDTODODIALOG_H

#include <QDialog>

namespace Ui {
class AddTodoDialog;
}

class AddTodoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTodoDialog(QWidget *parent = nullptr);
    ~AddTodoDialog();

private:
    Ui::AddTodoDialog *ui;
};

#endif // ADDTODODIALOG_H
