//
// Created by xavier on 3/13/24.
//

#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <format>


class AirportRecord {
public:

    /**
     * Split string str at delimiter dl returning a vector of the pieces
     * @param str string split
     * @param dl delimiter
     * @return vector containing pieces
     */
    std::vector<std::string> splitStrings(std::string str, char dl)
    {
        std::string word;

        // to count the number of split strings
        int num = 0;

        // adding delimiter character at the end
        // of 'str'
        str = str + dl;

        // length of 'str'
        int l = str.size();

        // traversing 'str' from left to right
        std::vector<std::string> substr_list;
        for (int i = 0; i < l; i++) {

            // if str[i] is not equal to the delimiter
            // character then accumulate it to 'word'
            if (str[i] != dl)
                word = word + str[i];

            else {

                // if 'word' is not an empty string,
                // then add this 'word' to the vector
                // 'substr_list[]'
                if ((int)word.size() != 0)
                    substr_list.push_back(word);

                // reset 'word'
                word = "";
            }
        }

        // return the splitted strings
        return substr_list;
    }

    /**
     * Split string str at delimiter dl returning a vector of the pieces
     * @param str string split
     * @param dl delimiter
     * @return vector containing pieces
     */
    static std::vector<std::string> splitString(std::string str, char dl)
    {
        std::string word;

        // to count the number of split strings
        int num = 0;

        // adding delimiter character at the end
        // of 'str'
        str = str + dl;

        // length of 'str'
        int l = str.size();

        // traversing 'str' from left to right
        std::vector<std::string> substr_list;
        for (int i = 0; i < l; i++) {

            // if str[i] is not equal to the delimiter
            // character then accumulate it to 'word'
            if (str[i] != dl)
                word = word + str[i];

            else {

                // if 'word' is not an empty string,
                // then add this 'word' to the vector
                // 'substr_list[]'
                if ((int)word.size() != 0)
                    substr_list.push_back(word);

                // reset 'word'
                word = "";
            }
        }

        // return the splitted strings
        return substr_list;
    }

    static std::list<AirportRecord> loadFromFile(std::string fileName) {
        std::string line;
        std::ifstream file;

        file.open(fileName);

        if (file.is_open()) {
            getline(file, line);
            const int numLines = std::stoi(line);
            std::list<AirportRecord> list;
            for (int i = 0; i < numLines; i++) {
                getline(file, line);
                std::vector<std::string> v = AirportRecord::splitString(line, ' ');
                auto airportRecord = new AirportRecord(v);
                list.emplace_back(*airportRecord);
            }


            file.close();
            return list;
        } else std::cout << "Unable to open file";

        return {};
    }

    AirportRecord(std::string* code, std::string* name, std::string* city, std::string* country,
                  int* latitudeDegree, int* latitudeMinutes, int* latitudeSeconds, std::string* direction,
                  int* longitudeDegree, int* longitudeMinutes, int* longitudeSeconds,
                  std::string* longitudeDirection, int* altitude){
        this->code = *code;
        this->name = *name;
        this->city = *city;
        this->country = *country;
        this->latitude_degree = *latitudeDegree;
        this->latitude_minutes = *latitudeMinutes;
        this->latitude_seconds = *latitudeSeconds;
        this->direction = *direction;
        this->longitude_degree = *longitudeDegree;
        this->longitude_minutes = *longitudeMinutes;
        this->longitude_seconds = *longitudeSeconds;
        this->longitude_direction = *longitudeDirection;
        this->altitude = *altitude;
    }

    explicit AirportRecord(std::vector<std::string> vector){
        code = vector[0];
        name = vector[1];
        city = vector[2];
        country = vector[3];
        latitude_degree = std::stoi(vector[4]);
        latitude_minutes = std::stoi(vector[5]);
        latitude_seconds = std::stoi(vector[6]);
        direction = vector[7];
        longitude_degree = std::stoi(vector[8]);
        longitude_minutes = std::stoi(vector[9]);
        longitude_seconds = std::stoi(vector[10]);
        longitude_direction = vector[11];
        altitude = std::stoi(vector[12]);
    }

    explicit AirportRecord(std::list<AirportRecord>::iterator iterator) {
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

    ~AirportRecord()=default;

    std::string toString(){
        return std::format("{} {} {} {} {} {} {} {} {} {} {} {} {}",
                           code, name, city, country,
                           latitude_degree, latitude_minutes, latitude_seconds, direction,
                           longitude_degree, longitude_minutes, longitude_seconds, longitude_degree,
                           altitude);
    }

    bool operator==(const AirportRecord &rhs) const {
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

    bool operator!=(const AirportRecord &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const AirportRecord &rhs) const {
        return altitude < rhs.altitude;
    }

    bool operator>(const AirportRecord &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const AirportRecord &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const AirportRecord &rhs) const {
        return !(*this < rhs);
    }

    void setAltitude(int *altitude) {
        AirportRecord::altitude = *altitude;
    }

    //GETTERS

    const std::string &getCode() const {
        return code;
    }

    const std::string &getName() const {
        return name;
    }

    const std::string &getCity() const {
        return city;
    }

    const std::string &getCountry() const {
        return country;
    }

    int getLatitudeDegree() const {
        return latitude_degree;
    }

    int getLatitudeMinutes() const {
        return latitude_minutes;
    }

    int getLatitudeSeconds() const {
        return latitude_seconds;
    }

    const std::string &getDirection() const {
        return direction;
    }

    int getLongitudeDegree() const {
        return longitude_degree;
    }

    int getLongitudeMinutes() const {
        return longitude_minutes;
    }

    int getLongitudeSeconds() const {
        return longitude_seconds;
    }

    const std::string &getLongitudeDirection() const {
        return longitude_direction;
    }

    int getAltitude() const {
        return altitude;
    }


private:
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    int latitude_degree;
    int latitude_minutes;
    int latitude_seconds;
    std::string direction;
    int longitude_degree;
    int longitude_minutes;
    int longitude_seconds;
    std::string longitude_direction;
    int altitude;

};




