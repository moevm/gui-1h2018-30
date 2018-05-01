#include "form.h"
#include "ui_form.h"
#include "QMessageBox"
#include "addepisodedialog.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form) {

        QFile file("myfile.txt");
        Serials serials;

        if (file.open(QIODevice::ReadOnly)) {
            Serial currentSerial;

            std::string name;
            int season;
            std::string howMuchWatchedStr;
            std::string seasonStr;
            bool isAlreadyWatched;
            int howMuchWatched;
            std::string comment;
            std::string temp;

            while (!file.atEnd()) {
                name = file.readLine().toStdString();

                if (name.size() > 0) {
                    name.erase(name.size() - 1);
                }

                seasonStr = file.readLine().toStdString();
                season = std::stoi(seasonStr);


                if (std::stoi(file.readLine().toStdString()) == 1) {
                    isAlreadyWatched = true;
                } else {
                    isAlreadyWatched = false;
                }


                howMuchWatchedStr = file.readLine().toStdString();
                howMuchWatched = std::stoi(howMuchWatchedStr);



                do {
                    temp = file.readLine().toStdString();
                    if (temp[0] == '@') {
                        break;
                    }
                    comment.append(temp);
                } while (file.canReadLine());

                currentSerial = Serial(name, season, isAlreadyWatched, howMuchWatched, comment);

                if (currentSerial.isAlreadyWatched) {
                    serials.addWatchedSerial(currentSerial);
                } else {
                    serials.addUnwatchedSerial(currentSerial);
                }
            }
            file.close();
        } else {
            std::cerr << "Error: file was not opened" << std::endl;
        }

        ui->setupUi(this);

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

Form::~Form() {
    Serials serials;

    QFile file("myfile.txt");

    if (file.open(QIODevice::WriteOnly)) {
        for (int i = 0; i < serials.sizeOfWatchedSerials; i++) {
            file.write(QByteArray::fromStdString(serials.watchedSerials[i].name));
            file.write("\n");
            file.write(QByteArray::fromStdString(std::to_string(serials.watchedSerials[i].season)));
            file.write("\n");
            file.write(QByteArray::fromStdString("1"));
            file.write("\n");
            file.write(QByteArray::fromStdString(std::to_string(serials.watchedSerials[i].howMuchWatched)));
            file.write("\n");
            file.write(QByteArray::fromStdString(serials.watchedSerials[i].comment));
            file.write("\n");
            file.write(QByteArray::fromStdString("@"));
            file.write("\n");
        }

        for (int i = 0; i < serials.sizeOfUnwatchedSerials; i++) {
            file.write(QByteArray::fromStdString(serials.unwatchedSerials[i].name));
            file.write("\n");
            file.write(QByteArray::fromStdString(std::to_string(serials.unwatchedSerials[i].season)));
            file.write("\n");
            file.write(QByteArray::fromStdString("0"));
            file.write("\n");
            file.write(QByteArray::fromStdString(std::to_string(serials.unwatchedSerials[i].howMuchWatched)));
            file.write("\n");
            file.write(QByteArray::fromStdString(serials.unwatchedSerials[i].comment));
            file.write("\n");
            file.write(QByteArray::fromStdString("@"));
            file.write("\n");
        }
    }
    delete ui;
}


void Form::on_addEpisode_clicked() {
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


void Form::on_serialsUnwatched_itemClicked(QListWidgetItem *item) {
    int currentRow = ui->serialsUnwatched->currentRow();
    Serials serials;
    serials.indexOfUnwatched = currentRow;
    serials.indexOfWatched = -1;



    Serial currentSerial = serials.unwatchedSerials[currentRow];

    ui->label_8->setText(QString::fromStdString(currentSerial.name));
    ui->label_9->setText(QString::fromStdString("Сезон " + std::to_string(currentSerial.season)));
    ui->label_10->setText(QString::fromStdString("Серия " + std::to_string(currentSerial.howMuchWatched)));
    ui->checkBox->setChecked(false);
    ui->textEdit->setText(QString::fromStdString(currentSerial.comment));
}

void Form::on_serialsWatched_itemClicked(QListWidgetItem *item) {
    int currentRow = ui->serialsWatched->currentRow();
    Serials serials;
    serials.indexOfUnwatched = -1;
    serials.indexOfWatched = currentRow;

    Serial currentSerial = serials.watchedSerials[currentRow];

    ui->label_8->setText(QString::fromStdString(currentSerial.name));
    ui->label_9->setText(QString::fromStdString("Сезон " + std::to_string(currentSerial.season)));
    ui->label_10->setText(QString::fromStdString("Серия " + std::to_string(currentSerial.howMuchWatched)));
    ui->checkBox->setChecked(true);
    ui->textEdit->setText(QString::fromStdString(currentSerial.comment));
}

void Form::on_checkBox_stateChanged(int arg1) {
    // arg1 = 0, если нажат, 2 если не нажат

    Serials serials;
    Serial currentSerial;

    if (arg1 == 0 && serials.indexOfWatched < 0) {
        return;
    }

    if (arg1 == 2 && serials.indexOfUnwatched < 0) {
        return;
    }

    if (serials.indexOfUnwatched >= 0) {
        currentSerial = serials.unwatchedSerials[serials.indexOfUnwatched];
        currentSerial.isAlreadyWatched = false;
        serials.unwatchedSerials.erase(serials.unwatchedSerials.begin() + serials.indexOfUnwatched);
        serials.sizeOfUnwatchedSerials--;
        serials.addWatchedSerial(currentSerial);
        serials.indexOfUnwatched = -1;
        serials.indexOfWatched = serials.sizeOfWatchedSerials - 1;
    } else if (serials.indexOfWatched >= 0) {
        currentSerial = serials.watchedSerials[serials.indexOfWatched];
        currentSerial.isAlreadyWatched = true;
        serials.watchedSerials.erase(serials.watchedSerials.begin() + serials.indexOfWatched);
        serials.sizeOfWatchedSerials--;
        serials.addUnwatchedSerial(currentSerial);
        serials.indexOfUnwatched = serials.sizeOfUnwatchedSerials - 1;
        serials.indexOfWatched = -1;
    } else {
        return;
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

void Form::on_pushButton_minus_clicked() {
    Serials serials;
    Serial currentSerial;

    if (serials.indexOfUnwatched >= 0) {
        if (serials.unwatchedSerials[serials.indexOfUnwatched].howMuchWatched > 0) {
            serials.unwatchedSerials[serials.indexOfUnwatched].howMuchWatched--;
            currentSerial = serials.unwatchedSerials[serials.indexOfUnwatched];
            ui->label_10->setText(QString::fromStdString("Серия " + std::to_string(currentSerial.howMuchWatched)));
        }
    } else if (serials.indexOfWatched >= 0) {
        if (serials.unwatchedSerials[serials.indexOfUnwatched].howMuchWatched > 0) {
            serials.watchedSerials[serials.indexOfWatched].howMuchWatched--;
            currentSerial = serials.unwatchedSerials[serials.indexOfUnwatched];
            ui->label_10->setText(QString::fromStdString("Серия " + std::to_string(currentSerial.howMuchWatched)));
        }
    } else {
        return;
    }
}

void Form::on_pushButton_plus_clicked() {
    Serials serials;
    Serial currentSerial;

    if (serials.indexOfUnwatched >= 0) {
        serials.unwatchedSerials[serials.indexOfUnwatched].howMuchWatched++;
        currentSerial = serials.unwatchedSerials[serials.indexOfUnwatched];
    } else if (serials.indexOfWatched >= 0) {
        serials.watchedSerials[serials.indexOfWatched].howMuchWatched++;
        currentSerial = serials.watchedSerials[serials.indexOfWatched];
    } else {
        return;
    }

    ui->label_10->setText(QString::fromStdString("Серия " + std::to_string(currentSerial.howMuchWatched)));
}

void Form::on_pushButton_delete_clicked() {
    Serials serials;

    if (serials.indexOfUnwatched >= 0) {
        serials.unwatchedSerials.erase(serials.unwatchedSerials.begin() + serials.indexOfUnwatched);
        serials.sizeOfUnwatchedSerials--;
    } else if (serials.indexOfWatched >= 0) {
        serials.watchedSerials.erase(serials.watchedSerials.begin() + serials.indexOfWatched);
        serials.sizeOfWatchedSerials--;
    } else {
        return;
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


void Form::on_textEdit_textChanged()
{
    Serials serials;
    if (serials.indexOfWatched >= 0) {
        serials.watchedSerials[serials.indexOfWatched].comment = ui->textEdit->toPlainText().toStdString();
    } else if (serials.indexOfUnwatched >= 0) {
        serials.unwatchedSerials[serials.indexOfUnwatched].comment = ui->textEdit->toPlainText().toStdString();
    } else {
        return;
    }
}
