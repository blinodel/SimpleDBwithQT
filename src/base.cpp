#include "mainwindow.h"
#include "base.h"
#include "ui_base.h"
#include "QSqlQuery"

base::base(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::base)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Data");
    if(db.open()){
        qDebug("База данных товаров успешно загружена");
    }
    else{
        qDebug("Ошибка базы данных товаров");
    }

    model = new QSqlTableModel(this, db);
    model->setTable("Products");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "Артикул", Qt::DisplayRole);
    model->setHeaderData(1, Qt::Horizontal, "Наименование", Qt::DisplayRole);
    model->setHeaderData(2, Qt::Horizontal, "Производитель", Qt::DisplayRole);
    model->setHeaderData(3, Qt::Horizontal, "Цена", Qt::DisplayRole);
    model->setHeaderData(4, Qt::Horizontal, "Кол-во", Qt::DisplayRole);


    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSortingEnabled(true);

}

base::~base()
{
    delete ui;
}




void base::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}



void base::on_updateButton_2_clicked()
{
    model = new QSqlTableModel(this, db);
    model->setTable("Products");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, "Артикул", Qt::DisplayRole);
    model->setHeaderData(1, Qt::Horizontal, "Наименование", Qt::DisplayRole);
    model->setHeaderData(2, Qt::Horizontal, "Производитель", Qt::DisplayRole);
    model->setHeaderData(3, Qt::Horizontal, "Цена", Qt::DisplayRole);
    model->setHeaderData(4, Qt::Horizontal, "Кол-во", Qt::DisplayRole);
    ui->tableView->setModel(model);
}


void base::on_searchButton_clicked()
{
    QString searchChoice = ui->searchsetting->currentText();

    if(searchChoice == "По артикулу"){
        QSqlQuery QueryLoadData;
        QueryLoadData.prepare("SELECT * FROM Products WHERE ID = :val");
        QueryLoadData.bindValue(":val", ui->searchLine->text());
        QueryLoadData.exec();
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(QueryLoadData);
        model->setHeaderData(0, Qt::Horizontal, "Артикул", Qt::DisplayRole);
        model->setHeaderData(1, Qt::Horizontal, "Наименование", Qt::DisplayRole);
        model->setHeaderData(2, Qt::Horizontal, "Производитель", Qt::DisplayRole);
        model->setHeaderData(3, Qt::Horizontal, "Цена", Qt::DisplayRole);
        model->setHeaderData(4, Qt::Horizontal, "Кол-во", Qt::DisplayRole);
        ui->tableView->setModel(model);
    }
    if(searchChoice == "По имени"){
        QSqlQuery QueryLoadData;
        QueryLoadData.prepare("SELECT * FROM Products WHERE Name = :val");
        QueryLoadData.bindValue(":val", ui->searchLine->text());
        QueryLoadData.exec();
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(QueryLoadData);
        model->setHeaderData(0, Qt::Horizontal, "Артикул", Qt::DisplayRole);
        model->setHeaderData(1, Qt::Horizontal, "Наименование", Qt::DisplayRole);
        model->setHeaderData(2, Qt::Horizontal, "Производитель", Qt::DisplayRole);
        model->setHeaderData(3, Qt::Horizontal, "Цена", Qt::DisplayRole);
        model->setHeaderData(4, Qt::Horizontal, "Кол-во", Qt::DisplayRole);
        ui->tableView->setModel(model);
    }
    if(searchChoice == "По производителю"){
        QSqlQuery QueryLoadData;
        QueryLoadData.prepare("SELECT * FROM Products WHERE Manufacturer = :val");
        QueryLoadData.bindValue(":val", ui->searchLine->text());
        QueryLoadData.exec();
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(QueryLoadData);
        model->setHeaderData(0, Qt::Horizontal, "Артикул", Qt::DisplayRole);
        model->setHeaderData(1, Qt::Horizontal, "Наименование", Qt::DisplayRole);
        model->setHeaderData(2, Qt::Horizontal, "Производитель", Qt::DisplayRole);
        model->setHeaderData(3, Qt::Horizontal, "Цена", Qt::DisplayRole);
        model->setHeaderData(4, Qt::Horizontal, "Кол-во", Qt::DisplayRole);
        ui->tableView->setModel(model);
    }
    if(searchChoice == "По цене"){
        QSqlQuery QueryLoadData;
        QueryLoadData.prepare("SELECT * FROM Products WHERE Price = :val");
        QueryLoadData.bindValue(":val", ui->searchLine->text());
        QueryLoadData.exec();
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(QueryLoadData);
        model->setHeaderData(0, Qt::Horizontal, "Артикул", Qt::DisplayRole);
        model->setHeaderData(1, Qt::Horizontal, "Наименование", Qt::DisplayRole);
        model->setHeaderData(2, Qt::Horizontal, "Производитель", Qt::DisplayRole);
        model->setHeaderData(3, Qt::Horizontal, "Цена", Qt::DisplayRole);
        model->setHeaderData(4, Qt::Horizontal, "Кол-во", Qt::DisplayRole);
        ui->tableView->setModel(model);
    }
    if(searchChoice == "По количеству"){
        QSqlQuery QueryLoadData;
        QueryLoadData.prepare("SELECT * FROM Products WHERE InStock = :val");
        QueryLoadData.bindValue(":val", ui->searchLine->text());
        QueryLoadData.exec();
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(QueryLoadData);
        model->setHeaderData(0, Qt::Horizontal, "Артикул", Qt::DisplayRole);
        model->setHeaderData(1, Qt::Horizontal, "Наименование", Qt::DisplayRole);
        model->setHeaderData(2, Qt::Horizontal, "Производитель", Qt::DisplayRole);
        model->setHeaderData(3, Qt::Horizontal, "Цена", Qt::DisplayRole);
        model->setHeaderData(4, Qt::Horizontal, "Кол-во", Qt::DisplayRole);
        ui->tableView->setModel(model);
    }
}

