#include "serials.h"
#include "serial.h"

int Serials::size = 0;
std::vector<Serial> Serials::serials;

Serials::Serials()
{
}

/*
void Serials::add(Serial serial)
{
    this->serials.push_back(serial);
    size++;
}
*/
void Serials::add(Serial serial)
{
    serials.push_back(serial);
    size++;
}
