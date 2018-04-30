#include "serials.h"
#include "serial.h"

int Serials::size = 0;
int Serials::sizeOfUnwatchedSerials = 0;
int Serials::sizeOfWatchedSerials = 0;
// std::vector<Serial> Serials::serials;
std::vector<Serial> Serials::watchedSerials;
std::vector<Serial> Serials::unwatchedSerials;

Serials::Serials()
{
}
/*
void Serials::add(Serial serial)
{
    serials.push_back(serial);
    size++;
}
*/

void Serials::addWatchedSerial(Serial serial)
{
    watchedSerials.push_back(serial);
    sizeOfWatchedSerials++;
}

void Serials::addUnwatchedSerial(Serial serial)
{
    unwatchedSerials.push_back(serial);
    sizeOfUnwatchedSerials++;
}

