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
    AddEpisodeDialog* a = new AddEpisodeDialog(this);
    a->exec();

    char name[64];
    int season;
    bool isAlreadyWatched;
    int seriesWatched;
    char comment[1024];

    char tmp[32];

    char aboutSerial[2048];

    std::ifstream fin("C:\\Users\\maxim\\Desktop\\gui\\usersData");
    /*
    while (!fin.eof()) {
        fin.getline(name, 64);
        fin >> season;
        fin.getline(tmp, 32);
        strcmp(tmp, "already watched") ? isAlreadyWatched = true : isAlreadyWatched = false;                  // ОЧЕНЬ ОПАСНОЕ МЕСТО
        fin >> seriesWatched;                                                                                 // И ОНО НЕ РАБОТАЕТ
        //(isAlreadyWatched == true) ? std::cout << "true" : std::cout << "false";
        fin.getline(comment, 1024);
        strcat(name, (char*)&season);
    }
    */

    fin.getline(name, 64);
    fin >> season;

    strcat(aboutSerial, name);
    strcat(aboutSerial, " сезон ");
    sprintf(tmp, "%d", season);
    strcat(aboutSerial, tmp); // просто привести к массиву чаров

    ui->serials->addItem(aboutSerial);

    fin.close();
}
