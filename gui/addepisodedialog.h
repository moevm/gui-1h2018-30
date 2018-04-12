#ifndef ADDEPISODEDIALOG_H
#define ADDEPISODEDIALOG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class AddEpisodeDialog;
}

class AddEpisodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEpisodeDialog(QWidget *parent = 0);
    ~AddEpisodeDialog();

private slots:
    void on_OK_clicked();

    void on_Cancel_clicked();

    void accept();

private:
    Ui::AddEpisodeDialog *ui;
};

#endif // ADDEPISODEDIALOG_H
