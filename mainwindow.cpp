#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>         /* srand, rand*/
#include <time.h>           /* time */
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize
    srand (time(NULL));

    //Generate (1-10)
    secretNumber = rand() %10 +1;
    qDebug() <<"Secret Number Generated : " << QString::number(secretNumber);
    ui->startOverButton->setDisabled(true);


    //Disable to Guess Button
    ui->guessButton->setDisabled(true);
    ui->startOverButton->setDisabled(false);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug() <<"Guess Number is :  " << QString::number(guessNumber);
    if (guessNumber == secretNumber)
    {
     //Congratulations
     ui->messageLabel->setText("Congratulations! :) , The number is:"+QString::number(secretNumber));
    }else {

        if (guessNumber < secretNumber)
        {
            ui->messageLabel->setText("The number is lower than that ");
        }

        if (guessNumber > secretNumber){
            ui->messageLabel->setText("The number is higher than that!");
        }
}
}

void MainWindow::on_startOverButton_clicked()
{
    //Enable the Guess Button
    ui->guessButton->setDisabled(false);
    //disable the start over button
    ui->startOverButton->setDisabled(true);
    //Put The SpinBox Back To1
    ui->spinBox->setValue(1);
    //Regenerate the random number
    secretNumber = rand()   % 10 +1;
    //Clear the message label
    ui->messageLabel->setText("");


}
