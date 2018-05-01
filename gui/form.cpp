#include "form.h"
#include "ui_form.h"
#include "QMessageBox"
#include "addepisodedialog.h"
#include <sstream>
#include <iostream>
#include <fstream>
// #include "serials.h"

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

    for (int i = 0; i < serials.sizeOfWatchedSerials; i++) {
        aboutSerial += serials.watchedSerials[i].name;
        aboutSerial += " сезон ";
        aboutSerial += std::to_string(serials.watchedSerials[i].season);

        ui->serialsWatched->addItem(QString::fromStdString(aboutSerial));

        aboutSerial = "";
    }

    for (int i = 0; i < serials.sizeOfUnwatchedSerials; i++) {
        aboutSerial += serials.unwatchedSerials[i].name;
        aboutSerial += " сезон ";
        aboutSerial += std::to_string(serials.unwatchedSerials[i].season);

        ui->serialsUnwatched->addItem(QString::fromStdString(aboutSerial));

        aboutSerial = "";
    }
}


void Form::on_serialsUnwatched_itemClicked(QListWidgetItem *item)
{
    int currentRow = ui->serialsUnwatched->currentRow();
    Serials serials;

    Serial currentSerial = serials.unwatchedSerials[currentRow];

    ui->label_8->setText(QString::fromStdString(currentSerial.name));
    ui->label_9->setText(QString::fromStdString("Сезон " + std::to_string(currentSerial.season)));
    ui->label_10->setText(QString::fromStdString("Серия " + std::to_string(currentSerial.howMuchWatched)));
    ui->checkBox->setChecked(false);
    ui->textEdit->setText(QString::fromStdString(currentSerial.comment));
}

void Form::on_serialsWatched_itemClicked(QListWidgetItem *item)
{
    int currentRow = ui->serialsWatched->currentRow();
    Serials serials;

    Serial currentSerial = serials.watchedSerials[currentRow];

    ui->label_8->setText(QString::fromStdString(currentSerial.name));
    ui->label_9->setText(QString::fromStdString("Сезон " + std::to_string(currentSerial.season)));
    ui->label_10->setText(QString::fromStdString("Серия " + std::to_string(currentSerial.howMuchWatched)));
    ui->checkBox->setChecked(true);
    ui->textEdit->setText(QString::fromStdString(currentSerial.comment));
}

void Form::on_checkBox_stateChanged(int arg1)
{
    // arg1 = 0, если нажат, 2 если не нажат
}

void Form::on_pushButton_minus_clicked()
{
    Serials serials;
    Serial currentSerial;
    int indexOfWatched = -1;
    int indexOfUnwatched = -1;
    for (int i = 0; i < serials.sizeOfUnwatchedSerials; i++) {
        if (serials.unwatchedSerials[i].name == ui->label_8->text().toStdString() &&
                "Сезон " + std::to_string(serials.unwatchedSerials[i].season) == ui->label_9->text().toStdString() &&
                "Серия " + std::to_string(serials.unwatchedSerials[i].howMuchWatched) == ui->label_10->text().toStdString() ) {
            currentSerial = serials.unwatchedSerials[i];
            indexOfUnwatched = i;
            break;
        }
    }

    for (int i = 0; i < serials.sizeOfWatchedSerials; i++) {
        if (serials.watchedSerials[i].name == ui->label_8->text().toStdString() &&
                "Сезон " + std::to_string(serials.watchedSerials[i].season) == ui->label_9->text().toStdString() &&
                "Серия " + std::to_string(serials.watchedSerials[i].howMuchWatched) == ui->label_10->text().toStdString() ) {
            currentSerial = serials.watchedSerials[i];
            indexOfWatched = i;
            break;
        }
    }

    if (currentSerial.howMuchWatched > 0) {
        if (indexOfUnwatched >= 0) {
            serials.unwatchedSerials[indexOfUnwatched].howMuchWatched--;
            currentSerial.howMuchWatched--;
        }
        if (indexOfWatched >= 0) {
            serials.watchedSerials[indexOfWatched].howMuchWatched--;
            currentSerial.howMuchWatched--;
        }

        ui->label_10->setText(QString::fromStdString("Серия " + std::to_string(currentSerial.howMuchWatched)));
    }
}

void Form::on_pushButton_plus_clicked()
{
    Serials serials;
    Serial currentSerial;
    int indexOfWatched = -1;
    int indexOfUnwatched = -1;
    for (int i = 0; i < serials.sizeOfUnwatchedSerials; i++) {
        if (serials.unwatchedSerials[i].name == ui->label_8->text().toStdString() &&
                "Сезон " + std::to_string(serials.unwatchedSerials[i].season) == ui->label_9->text().toStdString() &&
                "Серия " + std::to_string(serials.unwatchedSerials[i].howMuchWatched) == ui->label_10->text().toStdString() ) {
            currentSerial = serials.unwatchedSerials[i];
            indexOfUnwatched = i;
            break;
        }
    }

    for (int i = 0; i < serials.sizeOfWatchedSerials; i++) {
        if (serials.watchedSerials[i].name == ui->label_8->text().toStdString() &&
                "Сезон " + std::to_string(serials.watchedSerials[i].season) == ui->label_9->text().toStdString() &&
                "Серия " + std::to_string(serials.watchedSerials[i].howMuchWatched) == ui->label_10->text().toStdString() ) {
            currentSerial = serials.watchedSerials[i];
            indexOfWatched = i;
            break;
        }
    }


    if (indexOfUnwatched >= 0) {
        serials.unwatchedSerials[indexOfUnwatched].howMuchWatched++;
        currentSerial.howMuchWatched++;
    }
    if (indexOfWatched >= 0) {
        serials.watchedSerials[indexOfWatched].howMuchWatched++;
        currentSerial.howMuchWatched++;
    }

    ui->label_10->setText(QString::fromStdString("Серия " + std::to_string(currentSerial.howMuchWatched)));
}

void Form::on_pushButton_delete_clicked()
{
    Serials serials;
    Serial currentSerial;
    int indexOfWatched = -1;
    int indexOfUnwatched = -1;
    for (int i = 0; i < serials.sizeOfUnwatchedSerials; i++) {
        if (serials.unwatchedSerials[i].name == ui->label_8->text().toStdString() &&
                "Сезон " + std::to_string(serials.unwatchedSerials[i].season) == ui->label_9->text().toStdString() &&
                "Серия " + std::to_string(serials.unwatchedSerials[i].howMuchWatched) == ui->label_10->text().toStdString() ) {
            currentSerial = serials.unwatchedSerials[i];
            indexOfUnwatched = i;
            break;
        }
    }

    for (int i = 0; i < serials.sizeOfWatchedSerials; i++) {
        if (serials.watchedSerials[i].name == ui->label_8->text().toStdString() &&
                "Сезон " + std::to_string(serials.watchedSerials[i].season) == ui->label_9->text().toStdString() &&
                "Серия " + std::to_string(serials.watchedSerials[i].howMuchWatched) == ui->label_10->text().toStdString() ) {
            currentSerial = serials.watchedSerials[i];
            indexOfWatched = i;
            break;
        }
    }

    if (indexOfUnwatched >= 0) {
        serials.unwatchedSerials.erase(serials.unwatchedSerials.begin() + indexOfUnwatched);
        serials.sizeOfUnwatchedSerials--;
    }

    if (indexOfWatched >= 0) {
        serials.watchedSerials.erase(serials.watchedSerials.begin() + indexOfWatched);
        serials.sizeOfWatchedSerials--;
    }

    ui->serialsUnwatched->clear();
    ui->serialsWatched->clear();

    std::string aboutSerial;

    for (int i = 0; i < serials.sizeOfWatchedSerials; i++) {
        aboutSerial += serials.watchedSerials[i].name;
        aboutSerial += " сезон ";
        aboutSerial += std::to_string(serials.watchedSerials[i].season);

        ui->serialsWatched->addItem(QString::fromStdString(aboutSerial));

        aboutSerial = "";
    }

    for (int i = 0; i < serials.sizeOfUnwatchedSerials; i++) {
        aboutSerial += serials.unwatchedSerials[i].name;
        aboutSerial += " сезон ";
        aboutSerial += std::to_string(serials.unwatchedSerials[i].season);

        ui->serialsUnwatched->addItem(QString::fromStdString(aboutSerial));

        aboutSerial = "";
    }
}
