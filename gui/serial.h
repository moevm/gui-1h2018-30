#ifndef SERIAL_H
#define SERIAL_H

#include <string>

class Serial
{

private:
    std::string name;
    int season;
    bool isAlreadyWatched;
    int howMuchWatched;
    std::string comment;

public:
    Serial();
    Serial(std::string name, int season, bool isAlreadyWatched, int howMuchWatched, std::string comment);
};

#endif // SERIAL_H
