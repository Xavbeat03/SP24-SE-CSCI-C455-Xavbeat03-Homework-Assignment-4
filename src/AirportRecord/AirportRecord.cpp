//
// Created by xavier on 3/13/24.
//

#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include "AirportRecord.h"


std::list<AirportRecord> AirportRecord::loadFromFile(const std::string& fileName) {
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

    return {};
}

AirportRecord::AirportRecord(std::list<AirportRecord>::iterator iterator) {
    code = iterator->code;
    name = iterator->name;
    city = iterator->city;
    country = iterator->country;
    latitude_degree = iterator->latitude_degree;
    latitude_minutes = iterator->latitude_minutes;
    latitude_seconds = iterator->latitude_seconds;
    direction = iterator->direction;
    longitude_degree = iterator->longitude_degree;
    longitude_minutes = iterator->longitude_minutes;
    longitude_seconds = iterator->longitude_seconds;
    longitude_degree = iterator->longitude_degree;
    altitude = iterator->altitude;
}

bool AirportRecord::operator==(const AirportRecord &rhs) const {
    return code == rhs.code &&
           name == rhs.name &&
           city == rhs.city &&
           country == rhs.country &&
           latitude_degree == rhs.latitude_degree &&
           latitude_minutes == rhs.latitude_minutes &&
           latitude_seconds == rhs.latitude_seconds &&
           direction == rhs.direction &&
           longitude_degree == rhs.longitude_degree &&
           longitude_minutes == rhs.longitude_minutes &&
           longitude_seconds == rhs.longitude_seconds &&
           longitude_direction == rhs.longitude_direction &&
           altitude == rhs.altitude;
}

bool AirportRecord::operator!=(const AirportRecord &rhs) const {
    return !(rhs == *this);
}

bool AirportRecord::operator<(const AirportRecord &rhs) const {
    return altitude < rhs.altitude;
}

bool AirportRecord::operator>(const AirportRecord &rhs) const {
    return rhs < *this;
}

bool AirportRecord::operator<=(const AirportRecord &rhs) const {
    return !(rhs < *this);
}

bool AirportRecord::operator>=(const AirportRecord &rhs) const {
    return !(*this < rhs);
}

void AirportRecord::setAltitude(int *altitude) {
    AirportRecord::altitude = altitude;
}

std::string *AirportRecord::getCode() const {
    return code;
}

std::string *AirportRecord::getName() const {
    return name;
}

std::string *AirportRecord::getCity() const {
    return city;
}

std::string *AirportRecord::getCountry() const {
    return country;
}

int *AirportRecord::getLatitudeDegree() const {
    return latitude_degree;
}

int *AirportRecord::getLatitudeMinutes() const {
    return latitude_minutes;
}

int *AirportRecord::getLatitudeSeconds() const {
    return latitude_seconds;
}

std::string *AirportRecord::getDirection() const {
    return direction;
}

int *AirportRecord::getLongitudeDegree() const {
    return longitude_degree;
}

int *AirportRecord::getLongitudeMinutes() const {
    return longitude_minutes;
}

int *AirportRecord::getLongitudeSeconds() const {
    return longitude_seconds;
}

std::string *AirportRecord::getLongitudeDirection() const {
    return longitude_direction;
}

int *AirportRecord::getAltitude() const {
    return altitude;
}





