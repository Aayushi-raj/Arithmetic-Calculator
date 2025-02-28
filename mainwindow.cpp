#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connecting buttons to the correct functions
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::add);
    connect(ui->btnSub, &QPushButton::clicked, this, &MainWindow::subtract);
    connect(ui->btnMul, &QPushButton::clicked, this, &MainWindow::multiply);
    connect(ui->btnDiv, &QPushButton::clicked, this, &MainWindow::divide);
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::clear);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::calculate(char op) {
    bool ok1, ok2;
    double num1 = ui->lineEdit_1->text().toDouble(&ok1);
    double num2 = ui->lineEdit_2->text().toDouble(&ok2);

    if (!ok1 || !ok2) {
        ui->labelResult->setText("Error: Enter valid numbers!");
        return;
    }

    double result;
    if (op == '/' && num2 == 0) {
        ui->labelResult->setText("Error: Division by zero!");
        return;
    }

    switch (op) {
    case '+': result = num1 + num2; break;
    case '-': result = num1 - num2; break;
    case '*': result = num1 * num2; break;
    case '/': result = num1 / num2; break;
    default: return;
    }

    ui->labelResult->setText("Result: " + QString::number(result));
}

void MainWindow::add() { calculate('+'); }
void MainWindow::subtract() { calculate('-'); }
void MainWindow::multiply() { calculate('*'); }
void MainWindow::divide() { calculate('/'); }

void MainWindow::clear() {
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->labelResult->setText("Result: ");
}
