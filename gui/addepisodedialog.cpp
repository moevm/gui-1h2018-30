#include "addepisodedialog.h"
#include "ui_addepisodedialog.h"
#include "form.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include "serial.h"

AddEpisodeDialog::AddEpisodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEpisodeDialog)
{
    ui->setupUi(this);
}

AddEpisodeDialog::~AddEpisodeDialog()
{
    delete ui;
}

void AddEpisodeDialog::on_OK_clicked()
{
    this->accept();
}

void AddEpisodeDialog::on_Cancel_clicked()
{
    this->reject();
}


void AddEpisodeDialog::accept()
{

    Serials serials;

    Serial serial;
    serial.name = ui->name->text().toStdString();
    serial.season = ui->season->text().toInt();
    serial.isAlreadyWatched = ui->isAlreadyWatched->checkState();
    serial.howMuchWatched = ui->seriesWatched->text().toInt();
    serial.comment = ui->comment->toPlainText().toStdString();


    Serial newSerial(serial.name, serial.season, serial.isAlreadyWatched, serial.howMuchWatched, serial.comment);

    if (serial.isAlreadyWatched) {
        serials.addWatchedSerial(newSerial);
    } else {
        serials.addUnwatchedSerial(newSerial);
    }

    this->close();
}
