#include <gtest/gtest.h>

#include "../../src/PriorityQueue/PriorityQueue.cpp"

typedef PriorityQueue<int> pqueue;

namespace {
    TEST(ExtractMax, EmptyQueueTest1){
        auto* p = new pqueue();
        ASSERT_THROW(p->Extract_Max(), std::out_of_range);
    }
}