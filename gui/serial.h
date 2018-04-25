#ifndef SERIAL_H
#define SERIAL_H

#include <string>
#include <vector>

class Serial
{

public:
    std::string name;
    int season;
    bool isAlreadyWatched;
    int howMuchWatched;
    std::string comment;


    Serial();
    Serial(std::string name, int season, bool isAlreadyWatched, int howMuchWatched, std::string comment);
};

#endif // SERIAL_H
