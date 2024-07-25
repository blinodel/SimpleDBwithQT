#ifndef BASE_H
#define BASE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>

namespace Ui {
class base;
}

class base : public QDialog
{
    Q_OBJECT

public:
    explicit base(QWidget *parent = nullptr);
    ~base();

private slots:



    void on_tableView_clicked(const QModelIndex &index);


    void on_updateButton_2_clicked();

    void on_searchButton_clicked();

private:
    Ui::base *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    int currentRow;
};

#endif // BASE_H
