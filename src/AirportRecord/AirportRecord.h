//
// Created by xavier on 3/13/24.
//

#ifndef SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_AIRPORTRECORD_H
#define SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_AIRPORTRECORD_H


#include <string>
#include <utility>
#include <vector>

/**
    code - (string) The airport's International Air Transport Association's 3-letter code
    name - (string) Airport's name
    city - (string) City where the airport is located
    country - (string) Country where the airport is located
    latitude degree - (int) Airport's degrees latitude
    latitude minutes - (int) Airport's minutes latitude
    latitude seconds - (int) Airport's seconds latitude
    latitude direction - (string) N or S
    longitude degree - (int) Airport's degrees longitude
    longitude minutes - (int) Airport's minutes longitude
    longitude seconds - (int) Airport's seconds longitude
    longitude direction - (string) E or W
    altitude - (int) Airport's altitude in feet (KEY!!!!)
 */
class AirportRecord {
public:

    AirportRecord(std::string code, std::string name, std::string city, std::string country,
                  int latitudeDegree, int latitudeMinutes, int latitudeSeconds, std::string direction,
                  int longitudeDegree, int longitudeMinutes, int longitudeSeconds,
                  std::string longitudeDirection, int altitude) :
            code(std::move(code)), name(std::move(name)), city(std::move(city)),
            country(std::move(country)),
            latitude_degree(latitudeDegree),
            latitude_minutes(latitudeMinutes),
            latitude_seconds(latitudeSeconds),
            direction(std::move(direction)),
            longitude_degree(longitudeDegree),
            longitude_minutes(longitudeMinutes),
            longitude_seconds(longitudeSeconds),
            longitude_direction(std::move(longitudeDirection)),
            altitude(altitude) {}

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

    AirportRecord(std::list<AirportRecord>::iterator iterator);

    ~AirportRecord()= default;

    [[nodiscard]] const std::string &getCode() const {
        return code;
    }

    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    [[nodiscard]] const std::string &getCity() const {
        return city;
    }

    [[nodiscard]] const std::string &getCountry() const {
        return country;
    }

    [[nodiscard]] int getLatitudeDegree() const {
        return latitude_degree;
    }

    [[nodiscard]] int getLatitudeMinutes() const {
        return latitude_minutes;
    }

    [[nodiscard]] int getLatitudeSeconds() const {
        return latitude_seconds;
    }

    [[nodiscard]] const std::string &getDirection() const {
        return direction;
    }

    [[nodiscard]] int getLongitudeDegree() const {
        return longitude_degree;
    }

    [[nodiscard]] int getLongitudeMinutes() const {
        return longitude_minutes;
    }

    [[nodiscard]] int getLongitudeSeconds() const {
        return longitude_seconds;
    }

    [[nodiscard]] const std::string &getLongitudeDirection() const {
        return longitude_direction;
    }

    [[nodiscard]] int getAltitude() const {
        return altitude;
    }



    /**
     * Creates a list of Airport records from the file fileName
     * @param fileName the file to get records from
     * @return the list of Airport records
     */
    static std::list<AirportRecord> loadFromFile(std::string fileName);

    /**
     * Returns true if Airport record a has an elevation lower then b
     * @param a Airport record a
     * @param b Airport record b
     * @return true, if a's elevation is less than b's, false otherwise
     */
    static bool lessThan(AirportRecord a, AirportRecord b){
        return a.altitude < b.altitude;
    }

    bool operator==(const AirportRecord &rhs) const;

    bool operator!=(const AirportRecord &rhs) const;

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
public:
    void setAltitude(int altitude);

private:

    // function to split string into substrings on the
    // basis of delimiter and return the substrings
    // after split
    static std::vector<std::string> splitStrings(std::string str, char dl)
    {
        std::string word = "";

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

public:
    bool operator<(const AirportRecord &rhs) const;

    bool operator>(const AirportRecord &rhs) const;

    bool operator<=(const AirportRecord &rhs) const;

    bool operator>=(const AirportRecord &rhs) const;

};


#endif //SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_AIRPORTRECORD_H
