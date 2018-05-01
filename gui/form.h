#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QListWidgetItem>
#include "serials.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_addEpisode_clicked();

    void on_serialsUnwatched_itemClicked(QListWidgetItem *item);

    void on_serialsWatched_itemClicked(QListWidgetItem *item);

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_minus_clicked();

    void on_pushButton_plus_clicked();
    void on_pushButton_delete_clicked();

private:
    Ui::Form *ui;
};





#endif // FORM_H
