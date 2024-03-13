#include "PriorityQueue.h"


void PriorityQueue::Insert(std::tuple<int, AirportRecord> x) {
    map.insert(x);

}

std::tuple<int, AirportRecord> PriorityQueue::Maximum() {
    return std::tuple<int, AirportRecord>();
}

std::tuple<int, AirportRecord> PriorityQueue::Extract_Max() {
    return std::tuple<int, AirportRecord>();
}

void PriorityQueue::Increase_Key(int position, int new_key) {

}