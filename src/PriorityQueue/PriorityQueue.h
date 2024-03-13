#ifndef SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_PRIORITYQUEUE_H
#define SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_PRIORITYQUEUE_H

#include <map>
#include "../../src/MaxHeap/MaxHeap.cpp"
template <typename T>

class PriorityQueue {
public:

    PriorityQueue()=default;

    ~PriorityQueue()= default;
    /**
     * inserts map x into the priority queue
     * @param x the int, value map to be inserted
     */
    void Insert(std::tuple<int, T> x);

    /**
     * returns a copy of the key-value tuple that has the largest key in the priority queue
     * @return a key-value pair representing the largest key in the queue
     */
    std::tuple<int, T> Maximum();

    /**
     * removes the record from the priority queue and returns the key-value tuple that is with the largest key
     * @return a map representing the key-value map with the largest key
     */
    std::tuple<int, T> Extract_Max();

    /**
     * increases the value of the key located at position 'position' in the queue; new_key is required to be greater than the key already stored at location 'position'
     * @param position the position in the queue where the key will be increased
     * @param new_key the new key value for that position
     */
    void Increase_Key(int position, int new_key);
private:
    MaxHeap* maxHeap = new MaxHeap();
    std::map<int, T> map = new std::map<int, T>;

};




#endif //SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_PRIORITYQUEUE_H
