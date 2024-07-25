#ifndef adminbase_H
#define adminbase_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class adminbase;
}

class adminbase : public QDialog
{
    Q_OBJECT

public:
    explicit adminbase(QWidget *parent = nullptr);
    ~adminbase();

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_updateButton_2_clicked();

    void on_searchButton_clicked();

private:
    Ui::adminbase *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    int currentRow;
};

#endif // BASE_H
