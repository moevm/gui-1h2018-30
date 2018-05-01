#include "serials.h"
#include "serial.h"

int Serials::size = 0;
int Serials::sizeOfUnwatchedSerials = 0;
int Serials::sizeOfWatchedSerials = 0;
int Serials::indexOfUnwatched = -1;
int Serials::indexOfWatched = -1;
std::vector<Serial> Serials::watchedSerials;
std::vector<Serial> Serials::unwatchedSerials;

Serials::Serials(){
}

void Serials::addWatchedSerial(Serial serial) {
    watchedSerials.push_back(serial);
    sizeOfWatchedSerials++;
}

void Serials::addUnwatchedSerial(Serial serial) {
    unwatchedSerials.push_back(serial);
    sizeOfUnwatchedSerials++;
}

