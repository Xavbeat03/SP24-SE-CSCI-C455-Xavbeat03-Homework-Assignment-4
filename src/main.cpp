#include "PriorityQueue/PriorityQueue.cpp"
#include "AirportRecord/AirportRecord.cpp"


int main()
{
    std::list<AirportRecord> list = AirportRecord::loadFromFile("/home/xavier/CLionProjects/SP24-SE-CSCI-C455-Xavbeat03-Homework-Assignment-4/src/air16.txt");
    auto* p = new PriorityQueue<AirportRecord>;
    auto it = list.begin();
    for(int i = 0; i < list.size(); i++){
        p->Insert(AirportRecord(it));
        ++it;
    }
    while(p->getSize()>0)
        std::cout << p->Extract_Max().toString() << "\n";
}