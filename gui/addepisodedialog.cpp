#include "addepisodedialog.h"
#include "ui_addepisodedialog.h"
#include "form.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>

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
    //Serial serial(ui->name->text().toStdString(), ui->season->text().toInt(), ui->isAlreadyWatched->checkState(), ui->seriesWatched->text().toInt(), ui->comment->toPlainText().toStdString());

    Serial serial;
    serial.name = ui->name->text().toStdString();
    serial.season = ui->season->text().toInt();
    serial.isAlreadyWatched = ui->isAlreadyWatched->checkState();
    serial.howMuchWatched = ui->seriesWatched->text().toInt();
    serial.comment = ui->comment->toPlainText().toStdString();

    serials.add(serial);

    /*

    */

    this->close();
}
