#include <QApplication>
#include "form.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    Form f(nullptr);

    f.show();

    return application.exec();
}
