#include <list>
#include "AirportRecord/AirportRecord.h"
#include "PriorityQueue/PriorityQueue.h"

int main()
{
    std::list<AirportRecord> list = AirportRecord::loadFromFile("air16.txt");
    PriorityQueue p = new PriorityQueue();
}