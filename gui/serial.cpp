#include "serial.h"

Serial::Serial()
{

}

Serial::Serial(std::string name, int season, bool isAlreadyWatched, int howMuchWatched, std::string comment)
{
    this->name = name;
    this->season = season;
    this->isAlreadyWatched = isAlreadyWatched;
    this->howMuchWatched = howMuchWatched;
    this->comment = comment;
}
