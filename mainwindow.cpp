#include "mainwindow.h"
#include "ui_mainwindow.h"

double NoPertama;
bool userIsTypingNomorDua = false;

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   this->setWindowTitle("Calculator_Midterm Project");

   connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pencet()));
   connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pencet()));
   connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pencet()));
   connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pencet()));
   connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pencet()));
   connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pencet()));
   connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pencet()));
   connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pencet()));
   connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pencet()));
   connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pencet()));

   connect(ui->pushButton_plusmin,SIGNAL(released()),this,SLOT(uner_operasi_pressed()));
   connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(uner_operasi_pressed()));

   connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(operasi_binary_pressed()));
   connect(ui->pushButton_min,SIGNAL(released()),this,SLOT(operasi_binary_pressed()));
   connect(ui->pushButton_mpy,SIGNAL(released()),this,SLOT(operasi_binary_pressed()));
   connect(ui->pushButton_div,SIGNAL(released()),this,SLOT(operasi_binary_pressed()));

   ui->pushButton_plus->setCheckable(true);
   ui->pushButton_min->setCheckable(true);
   ui->pushButton_mpy->setCheckable(true);
   ui->pushButton_div->setCheckable(true);

   ui->comboBox->addItem(QIcon(":/celsius.ico"),"Celsius");
   ui->comboBox->addItem(QIcon(":/fahrenheit.ico"), "Fahrenheit");
   ui->comboBox->addItem(QIcon(":/kelvin.ico"), "Kelvin");

   ui->comboBox_2->addItem(QIcon(":/celsius.ico"),"Celsius");
   ui->comboBox_2->addItem(QIcon(":/fahrenheit.ico"), "Fahrenheit");
   ui->comboBox_2->addItem(QIcon(":/kelvin.ico"), "Kelvin");
}


MainWindow::~MainWindow()
{
   delete ui;
}

void  MainWindow::digit_pencet()
{
   QPushButton * button = (QPushButton*)sender();

   double labelNomor;
   QString labelbaru;

   if ((ui->pushButton_plus->isChecked() || ui->pushButton_min->isChecked() ||
        ui->pushButton_mpy->isChecked() || ui->pushButton_div->isChecked()) && (!userIsTypingNomorDua))
   {
       labelNomor = button->text().toDouble();
       userIsTypingNomorDua = true;
       labelbaru = QString::number(labelNomor, 'g', 11);
   }
   else
   {
       if (ui->label->text().contains('.') and button->text() == "0")
       {
           labelbaru = ui->label->text() + button->text();
       }
       else
       {
           labelNomor = (ui->label->text() + button->text()).toDouble();
           labelbaru = QString::number(labelNomor, 'g', 11);
       }
       labelNomor = (ui->label->text() + button->text()).toDouble();
   }

   ui->label->setText(labelbaru);
}

void MainWindow::on_pushButton_desimal_released()
{
   ui->label->setText(ui->label->text() + ".");
}

void MainWindow::uner_operasi_pressed()
{
   QPushButton * button = (QPushButton*)sender();

   double labelNomor;
   QString labelbaru;

   if (button->text() == "+/-")
   {
       labelNomor = ui->label->text().toDouble();
       labelNomor = labelNomor * -1;
       labelbaru = QString::number(labelNomor, 'g', 11);
       ui->label->setText(labelbaru);
   }

   if (button->text() == "%")
   {
       labelNomor = ui->label->text().toDouble();
       labelNomor = labelNomor * 0.01;
       labelbaru = QString::number(labelNomor, 'g', 11);
       ui->label->setText(labelbaru);
   }
}

void MainWindow::on_pushButton_cls_released()
{
   ui->pushButton_plus->setChecked(false);
   ui->pushButton_min->setChecked(false);
   ui->pushButton_mpy->setChecked(false);
   ui->pushButton_div->setChecked(false);

   userIsTypingNomorDua = false;

   ui->label->setText("0");
}

void MainWindow::on_pushButton_equel_released()
{
   double labelNomor, NoDua;
   QString labelbaru;

   NoDua = ui->label->text().toDouble();

   if (ui->pushButton_plus->isChecked())
   {
       labelNomor = NoPertama + NoDua;
       labelbaru = QString::number(labelNomor,'g', 11);
       ui->label->setText(labelbaru);
       ui->pushButton_plus->setChecked(false);
   }

   else if (ui->pushButton_min->isChecked())
   {
       labelNomor = NoPertama - NoDua;
       labelbaru = QString::number(labelNomor,'g', 11);
       ui->label->setText(labelbaru);
       ui->pushButton_min->setChecked(false);
   }

   else if (ui->pushButton_mpy->isChecked())
   {
       labelNomor = NoPertama * NoDua;
       labelbaru = QString::number(labelNomor,'g', 11);
       ui->label->setText(labelbaru);
       ui->pushButton_mpy->setChecked(false);
   }

   else if (ui->pushButton_div->isChecked())
   {
       labelNomor = NoPertama / NoDua;
       labelbaru = QString::number(labelNomor,'g', 11);
       ui->label->setText(labelbaru);
       ui->pushButton_div->setChecked(false);
   }

   userIsTypingNomorDua = false;
}

void MainWindow::operasi_binary_pressed()
{
   QPushButton * button = (QPushButton*) sender();

   NoPertama = ui->label->text().toDouble();

   button->setChecked(true);
}

void MainWindow::on_pushButton_clicked()
{
    QString first = ui->comboBox->currentText();
    QString  second = ui->comboBox_2->currentText();

   if(first==second){

  QString amount= ui->lineEdit->text();
  ui->lineEdit_2->setText(amount);
   }

   else if(first=="Celsius"){


      if(second=="Fahrenheit")
      {
          QString amount= ui->lineEdit->text();
          float n = amount.toFloat();
          float curr;
          curr= (n * 9/5) + 32;
          ui->lineEdit_2->setText(QString::number(curr));
      }

      else if(second=="Kelvin")
      {
          QString amount = ui->lineEdit->text();
          float n = amount.toFloat();
          float curr;
          curr = n + 273.5;
          ui->lineEdit_2->setText(QString::number(curr));
       }
}

   else if(first=="Fahrenheit"){

        if(second=="Celsius")
        {
             QString amount= ui->lineEdit->text();
             float n = amount.toFloat();
             float curr;
             curr= (n - 32) * 5/9;
             ui->lineEdit_2->setText(QString::number(curr));
        }

         else if(second == "Kelvin")
        {
             QString amount = ui->lineEdit->text();
             float n = amount.toFloat();
             float curr;
             curr = (n - 32) * 5/9 + 273.15;
             ui->lineEdit_2->setText(QString::number(curr));
        }
     }

  else if(first=="Kelvin"){

       if(second=="Celsius")
       {
           QString amount= ui->lineEdit->text();
           float n = amount.toFloat();
           float curr;
           curr= n - 273.15;
           ui->lineEdit_2->setText(QString::number(curr));
       }

       else if(second == "Fahrenheit")
       {
           QString amount = ui->lineEdit->text();
           float n = amount.toFloat();
           float curr;
           curr = ((n - 273.15) * 9/5 + 32);
           ui->lineEdit_2->setText(QString::number(curr));
       }
    }
}
