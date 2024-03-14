#include "AirportRecord/AirportRecord.cpp"
#include "PriorityQueue/PriorityQueue.cpp"

int main()
{
    std::list<AirportRecord> list = AirportRecord::loadFromFile("air16.txt");
    auto* p = new PriorityQueue<AirportRecord>;
    auto it = list.begin();
    for(int i = 0; i < list.size(); i++){
        p->Insert(AirportRecord(it->getCode(), it->getName(), it->getCity(), it->getCountry(),
                                it->getLatitudeDegree(), it->getLatitudeMinutes(), it->getLatitudeSeconds(),
                                it->getDirection(), it->getLongitudeDegree(), it->getLongitudeMinutes(), it->getLongitudeSeconds(),
                                it->getLongitudeDirection(), it->getAltitude()));
        ++it;
    }
    while(p->getSize()>0)
        p->Extract_Max().toString();
}