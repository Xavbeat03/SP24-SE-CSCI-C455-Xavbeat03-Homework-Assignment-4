//
// Created by xavier on 3/13/24.
//

#ifndef SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_AIRPORTRECORD_H
#define SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_AIRPORTRECORD_H


#include <format>

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

    AirportRecord(std::string* code, std::string* name, std::string* city, std::string* country,
                  int* latitudeDegree, int* latitudeMinutes, int* latitudeSeconds, std::string* direction,
                  int* longitudeDegree, int* longitudeMinutes, int* longitudeSeconds,
                  std::string* longitudeDirection, int* altitude) :
            code(code), name(name), city(city),
            country(country),
            latitude_degree(latitudeDegree),
            latitude_minutes(latitudeMinutes),
            latitude_seconds(latitudeSeconds),
            direction(direction),
            longitude_degree(longitudeDegree),
            longitude_minutes(longitudeMinutes),
            longitude_seconds(longitudeSeconds),
            longitude_direction(longitudeDirection),
            altitude(altitude) {}

    explicit AirportRecord(std::vector<std::string> vector){
        code = &vector[0];
        name = &vector[1];
        city = &vector[2];
        country = &vector[3];
        latitude_degree = reinterpret_cast<int *>(std::stoi(vector[4]));
        latitude_minutes = reinterpret_cast<int *>(std::stoi(vector[5]));
        latitude_seconds = reinterpret_cast<int *>(std::stoi(vector[6]));
        direction = &vector[7];
        longitude_degree = reinterpret_cast<int *>(std::stoi(vector[8]));
        longitude_minutes = reinterpret_cast<int *>(std::stoi(vector[9]));
        longitude_seconds = reinterpret_cast<int *>(std::stoi(vector[10]));
        longitude_direction = &vector[11];
        altitude = reinterpret_cast<int *>(std::stoi(vector[12]));
    }

    explicit AirportRecord(std::list<AirportRecord>::iterator iterator);

    ~AirportRecord()= default;

    /**
     * Creates a list of Airport records from the file fileName
     * @param fileName the file to get records from
     * @return the list of Airport records
     */
    static std::list<AirportRecord> loadFromFile(const std::string& fileName);

    bool operator==(const AirportRecord &rhs) const;

    bool operator!=(const AirportRecord &rhs) const;

    bool operator<(const AirportRecord &rhs) const;

    bool operator>(const AirportRecord &rhs) const;

    bool operator<=(const AirportRecord &rhs) const;

    bool operator>=(const AirportRecord &rhs) const;

    /**
     * Sets the altitude of the airport record
     * @param altitude new altitude
     */
    void setAltitude(int *altitude);

    std::string *getCode() const;

    std::string *getName() const;

    std::string *getCity() const;

    std::string *getCountry() const;

    int *getLatitudeDegree() const;

    int *getLatitudeMinutes() const;

    int *getLatitudeSeconds() const;

    std::string *getDirection() const;

    int *getLongitudeDegree() const;

    int *getLongitudeMinutes() const;

    int *getLongitudeSeconds() const;

    std::string *getLongitudeDirection() const;

    int *getAltitude() const;


    std::string toString(){
        return std::format("{} {} {} {} {} {} {} {} {} {} {} {} {}",
                           *code, *name, *city, *country,
                           *latitude_degree, *latitude_minutes, *latitude_seconds, *direction,
                           *longitude_degree, *longitude_minutes, *longitude_seconds, *longitude_degree,
                           *altitude);
    }

private:
    std::string* code{};
    std::string* name{};
    std::string* city{};
    std::string* country{};
    int* latitude_degree{};
    int* latitude_minutes{};
    int* latitude_seconds{};
    std::string* direction{};
    int* longitude_degree{};
    int* longitude_minutes{};
    int* longitude_seconds{};
    std::string* longitude_direction{};
    int* altitude{};

    // function to split string into substrings on the
    // basis of delimiter and return the substrings
    // after split
    static std::vector<std::string> splitStrings(std::string str, char dl)
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

};


#endif //SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_AIRPORTRECORD_H
