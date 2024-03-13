//
// Created by xavier on 3/13/24.
//

#include <fstream>
#include <iostream>
#include <list>
#include "AirportRecord.h"


std::list<AirportRecord> AirportRecord::loadFromFile(std::string fileName) {
    std::string line;
    std::ifstream file (fileName);
    if(file.is_open())
    {
        getline(file, line);
        const int numLines = std::stoi(line);
        std::list<AirportRecord> list;
        for(int i = 0; i < numLines; i++){
            getline(file, line);
            std::vector<std::string> v = splitStrings(line, ' ');
            auto airportRecord = new AirportRecord(v);
            list.emplace_back(*airportRecord);
        }


        file.close();
        return list;
    }
    else std::cout << "Unable to open file";
}
