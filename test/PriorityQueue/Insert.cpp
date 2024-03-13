#include <gtest/gtest.h>

#include "../../src/PriorityQueue/PriorityQueue.cpp"

typedef PriorityQueue<int> pqueue;

namespace {
   TEST(Insert, EmptyQueueTest1){
       auto* p = new pqueue();
       p->Insert(3);
        ASSERT_EQ(3, p->Maximum());
        ASSERT_EQ(1, p->getSize());
   }

    TEST(Insert, EmptyQueueTest2){
        auto* p = new pqueue();
        p->Insert(5);
        ASSERT_EQ(5, p->Maximum());
        ASSERT_EQ(1, p->getSize());
    }

    TEST(Insert, SingleQueueTest1){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(7);
        ASSERT_EQ(7, p->Maximum());
        ASSERT_EQ(2, p->getSize());
    }

    TEST(Insert, SingleQueueTest2){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(3);
        ASSERT_EQ(5, p->Maximum());
        ASSERT_EQ(2, p->getSize());
    }

    TEST(Insert, DoubleQueueTest1){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(3);
        p->Insert(4);
        ASSERT_EQ(5, p->Maximum());
        ASSERT_EQ(3, p->getSize());
    }

    TEST(Insert, DoubleQueueTest2){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(6);
        p->Insert(4);
        ASSERT_EQ(6, p->Maximum());
        ASSERT_EQ(3, p->getSize());
    }

    TEST(Insert, TripleQueueTest1){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(6);
        p->Insert(4);
        p->Insert(7);
        ASSERT_EQ(7, p->Maximum());
        ASSERT_EQ(4, p->getSize());
    }

    TEST(Insert, TripleQueueTest2){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(6);
        p->Insert(4);
        p->Insert(1);
        ASSERT_EQ(6, p->Maximum());
        ASSERT_EQ(4, p->getSize());
    }
}