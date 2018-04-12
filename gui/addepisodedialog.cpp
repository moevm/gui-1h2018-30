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


void AddEpisodeDialog::accept() {
    std::ofstream fout("C:\\Users\\maxim\\Desktop\\gui\\usersData", std::ios::app);

    std::string string;
    string.append(ui->name->text().toStdString());
    string.append("\n");
    string.append(ui->season->text().toStdString());
    string.append("\n");
    ui->isAlreadyWatched->checkState() ? string.append("already watched") : string.append("has not already watched");
    string.append("\n");
    string.append(ui->seriesWatched->text().toStdString());
    string.append("\n");
    string.append(ui->comment->toPlainText().toStdString());
    string.append("\n");
    string.append("commentend");
    string.append("\n");
    fout << string;

    fout.close();

    this->close();
}
