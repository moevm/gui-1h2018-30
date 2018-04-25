#include "form.h"
#include "ui_form.h"
#include "QMessageBox"
#include "addepisodedialog.h"
#include <sstream>
#include <iostream>
#include <fstream>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_addEpisode_clicked()
{
    Serials serials;
    AddEpisodeDialog* a = new AddEpisodeDialog(this);


    a->exec();
    ui->serialsUnwatched->clear();
    ui->serialsWatched->clear();

    std::string aboutSerial;

    for (int i = 0; i < serials.size; i++) {
        aboutSerial += serials.serials[i].name;
        aboutSerial += " сезон ";
        aboutSerial += std::to_string(serials.serials[i].season);

        if (!serials.serials[i].isAlreadyWatched) {
            ui->serialsUnwatched->addItem(QString::fromStdString(aboutSerial));
        } else {
            ui->serialsWatched->addItem(QString::fromStdString(aboutSerial));
        }
        aboutSerial = "";
    }
}
