#ifndef SERIALS_H
#define SERIALS_H
#include "serial.h"
#include <vector>

class Serials
{
public:
    static int size;
    static std::vector<Serial> serials;
    static void add(Serial serial);
    Serials();
};

#endif // SERIALS_H
