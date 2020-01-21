#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_guessButton_clicked();

    void on_startOverButton_clicked();

private:
    Ui::MainWindow *ui;
    int secretNumber, guessNumber;
};

#endif // MAINWINDOW_H
