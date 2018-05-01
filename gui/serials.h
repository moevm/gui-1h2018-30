#ifndef SERIALS_H
#define SERIALS_H
#include "serial.h"
#include <vector>

class Serials
{
public:
    static int size;
    static int sizeOfWatchedSerials;
    static int sizeOfUnwatchedSerials;
    static int indexOfWatched;
    static int indexOfUnwatched;

    // static std::vector<Serial> serials;

    static std::vector<Serial> watchedSerials;
    static std::vector<Serial> unwatchedSerials;

    // static void add(Serial serial);

    static void addWatchedSerial(Serial serial);
    static void addUnwatchedSerial(Serial serial);

    Serials();
};

#endif // SERIALS_H
