#include <QApplication>
#include "form.h"
#include "serials.h"

//Serials serials;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    Form f(nullptr);

    f.show();

    return application.exec();
}
