#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "base.h"
#include "adminbase.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move(screen()->geometry().center() - frameGeometry().center());


    users = QSqlDatabase::addDatabase("QSQLITE");
    users.setDatabaseName("Data");
    if (users.open()){
        qDebug() << "База данных пользователей успешно загружена";
    }
    else{
        qDebug() << "Ошибка базы данных пользователей";
    }
}

MainWindow::~MainWindow()
{
    users.close();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //запрашиваем данные у пользователя
    qDebug() << "запрашиваем данные у пользователя";
    QString Login = ui->login->text();
    QString Password = ui->password->text();
    QString Location = ui->location->currentText();

    QSqlQueryModel queryModel; //создание запроса
    queryModel.setQuery("SELECT * FROM UserData"); //подтягиваем пользователей из базы данных
    qDebug() << queryModel.rowCount();

    for (int i = 0; i < queryModel.rowCount(); i++) //цикл для проверки введенных данных
    {
        //принимаем данные из таблицы для сравнения
        qDebug() << "принимаем данные из таблицы для сравнения";
        QString dbLogin = queryModel.record(i).field(0).value().toString();
        QString dbPassword = queryModel.record(i).field(1).value().toString();
        QString dbLocation = queryModel.record(i).field(2).value().toString();
        if (Login == dbLogin && Password == dbPassword && Location == dbLocation && dbLocation == "Склад"){ //вход в базу при совпадении
            hide();
            adminbase Stock; //создание объекта класса adminbase
            Stock.setModal(true);
            Stock.exec();
            break;
        }
        else if(Login == dbLogin && Password == dbPassword && Location == dbLocation && dbLocation == "Магазин"){
            hide();
            base Stock; //создание объекта класса base
            Stock.setModal(true);
            Stock.exec();
            break;
        }
        else{ //продолжаем поиск при несоответсвии данных
            if(i + 1 == queryModel.rowCount()){ //если это последняя итерация и логин с паролем так и не совпали, то выводим ошибку
                QMessageBox::warning(this, "Внимание!", "Введен неверный логин или пароль!");
            }
            continue; //продолжаем линейный поиск по базе
        }        
    }

}

