#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    number1 = "";
    number2 = "";
    state = 0;
    operand = -1;
    result = 0.0;

    QList<QPushButton*> numButtons = { ui->N0, ui->N1, ui->N2, ui->N3, ui->N4, ui->N5, ui->N6, ui->N7, ui->N8, ui->N9 };
    for (QPushButton* button : numButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    }

    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);

    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::numberClickedHandler(){

    QPushButton * button = qobject_cast<QPushButton*>(sender());

    QString name = button->objectName();
    qDebug() << "Button name:" << name;

    int digit = button->property("numValue").toInt();
    qDebug() << "Button value:" << digit;

    if (state == 0) {
        number1 += QString::number(digit);
        ui->num1->setText(number1);
    }
    else if (state == 2){
        number2 += QString::number(digit);
        ui->num2->setText(number2);
    }

}


void MainWindow::addSubMulDivClickHandler(){

    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString op = button->text();

    if (op == "+") operand = 0;
    else if (op == "-") operand = 1;
    else if (op == "*") operand = 2;
    else if (op == "/") operand = 3;

    qDebug() << "Selected operation:" << op;

    state = 2;
}

void MainWindow::clearAndEnterClickHandler(){

    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if (button == ui->clear){
        resetLineEdits();
        return;
    }

    float n1 = number1.toFloat();
    float n2 = number2.toFloat();

    qDebug() << "number 1 =" << n1 << " and number 2 = " << n2;

    switch (operand){
    case 0: result = n1 + n2; break;
    case 1: result = n1 - n2; break;
    case 2: result = n1 * n2; break;
    case 3: result = n1 / n2; break;

    /*case 3:
        if (n2 != 0) result = n1 / n2;
        else {
            ui->Result->setText("Error");
            return;
        }
        break;*/
    }

    ui->Result->setText(QString::number(result));
    qDebug() << "Calculation result:" << result;
}

void MainWindow::resetLineEdits(){

    number1 = "";
    number2 = "";
    result = 0;
    state = 0;
    operand = -1;

    ui->num1->clear();
    ui->num2->clear();
    ui->Result->clear();
}

























































