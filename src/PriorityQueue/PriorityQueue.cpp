#include "PriorityQueue.h"


void PriorityQueue::Insert(std::tuple<int, AirportRecord> x) {
    AirportRecord a = std::get<1>(x);
    list->emplace_back(a);
    maxHeap->insert(a.getAltitude());
}

std::tuple<int, AirportRecord> PriorityQueue::Maximum() {
    for(const AirportRecord& a: *list){
        if(a.getAltitude() == maxHeap->peekAtRoot()){
            return std::make_tuple(maxHeap->peekAtRoot(), a);
        }
    }
    throw std::out_of_range("No items in queue");
}

std::tuple<int, AirportRecord> PriorityQueue::Extract_Max() {
    std::tuple<int, AirportRecord> a = Maximum();
    maxHeap->retrieveAndRemoveRoot();
    std::list<AirportRecord>::iterator myitr;
    while((AirportRecord) myitr != std::get<1>(a))
        myitr++;
    list->erase(myitr);
    return a;
}

void PriorityQueue::Increase_Key(int position, int new_key) {
    MaxHeap m = *maxHeap;
    m.Heapsort();

    int k = m.valueAt(m.getSize()-position);
    if(new_key <= k)return;

    m.replaceAt(m.getSize()-position, new_key);
    list->
}
