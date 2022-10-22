#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pencet();
    void on_pushButton_desimal_released();
    void uner_operasi_pressed();
    void on_pushButton_cls_released();
    void on_pushButton_equel_released();
    void operasi_binary_pressed();
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
