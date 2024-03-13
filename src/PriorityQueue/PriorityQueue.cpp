#include "PriorityQueue.h"

template<typename T>
T PriorityQueue<T>::Maximum() {
    return maxHeap->peekAtRoot();
}

template<typename T>
void PriorityQueue<T>::Insert(T x) {
    maxHeap->insert(x);
}

template<typename T>
T PriorityQueue<T>::Extract_Max() {
    return maxHeap->retrieveAndRemoveRoot();
}

template<typename T>
void PriorityQueue<T>::Increase_Key(int position, T new_key) {
    if (maxHeap->valueAt(position) < new_key){
        return;
    } else {
        maxHeap->replaceAt(position, new_key);
    }
}