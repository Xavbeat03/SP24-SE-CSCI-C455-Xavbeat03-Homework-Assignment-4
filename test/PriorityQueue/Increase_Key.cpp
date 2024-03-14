#include <gtest/gtest.h>

#include "../../src/PriorityQueue/PriorityQueue.cpp"

typedef PriorityQueue<int> pqueue;

namespace {

    TEST(IncreaseKey, EmptyQueueTest1){
        auto* p = new pqueue();
        ASSERT_THROW(p->Increase_Key(0, 2), std::out_of_range);
    }

    TEST(IncreaseKey, SingleQueueTest1){
        auto* p = new pqueue();
        p->Insert(1);
        p->Increase_Key(0, 2);
        ASSERT_EQ(2, p->Maximum());
        ASSERT_EQ(1, p->getSize());
    }

    TEST(IncreaseKey, SingleQueueTest2){
        auto* p = new pqueue();
        p->Insert(1);
        p->Increase_Key(0, 3);
        ASSERT_EQ(3, p->Maximum());
        ASSERT_EQ(1, p->getSize());
    }

    TEST(IncreaseKey, DoubleQueueTest1){
        auto* p = new pqueue();
        p->Insert(1);
        p->Insert(1);
        p->Increase_Key(0, 3);
        ASSERT_EQ(3, p->Maximum());
        ASSERT_EQ(2, p->getSize());
    }

    TEST(IncreaseKey, DoubleQueueTest2){
        auto* p = new pqueue();
        p->Insert(1);
        p->Insert(2);
        p->Increase_Key(1, 3);
        ASSERT_EQ(3, p->Maximum());
        ASSERT_EQ(2, p->getSize());
    }

    TEST(IncreaseKey, TripleQueueTest1){
        auto* p = new pqueue();
        p->Insert(1);
        p->Insert(2);
        p->Insert(3);
        p->Increase_Key(2, 3);
        ASSERT_EQ(3, p->Extract_Max());
        ASSERT_EQ(2, p->getSize());
        ASSERT_EQ(3, p->Extract_Max());
        ASSERT_EQ(1, p->getSize());
    }

}