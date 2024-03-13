#include <gtest/gtest.h>

#include "../../src/PriorityQueue/PriorityQueue.cpp"

typedef PriorityQueue<int> pqueue;

namespace {
    TEST(Maximum, EmptyQueueTest1){
        auto* p = new pqueue();
        p->Insert(3);
        ASSERT_EQ(3, p->Maximum());
        ASSERT_EQ(3, p->Maximum());
        ASSERT_EQ(1, p->getSize());
    }

    TEST(Maximum, EmptyQueueTest2){
        auto* p = new pqueue();
        p->Insert(5);
        ASSERT_EQ(5, p->Maximum());
        ASSERT_EQ(5, p->Maximum());
        ASSERT_EQ(1, p->getSize());
    }

    TEST(Maximum, SingleQueueTest1){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(7);
        ASSERT_EQ(7, p->Maximum());
        ASSERT_EQ(7, p->Maximum());
        ASSERT_EQ(2, p->getSize());
    }

    TEST(Maximum, SingleQueueTest2){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(3);
        ASSERT_EQ(5, p->Maximum());
        ASSERT_EQ(5, p->Maximum());
        ASSERT_EQ(2, p->getSize());
    }

    TEST(Maximum, DoubleQueueTest1){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(3);
        p->Insert(4);
        ASSERT_EQ(5, p->Maximum());
        ASSERT_EQ(5, p->Maximum());
        ASSERT_EQ(3, p->getSize());
    }

    TEST(Maximum, DoubleQueueTest2){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(6);
        p->Insert(4);
        ASSERT_EQ(6, p->Maximum());
        ASSERT_EQ(6, p->Maximum());
        ASSERT_EQ(3, p->getSize());
    }

    TEST(Maximum, TripleQueueTest1){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(6);
        p->Insert(4);
        p->Insert(7);
        ASSERT_EQ(7, p->Maximum());
        ASSERT_EQ(7, p->Maximum());
        ASSERT_EQ(4, p->getSize());
    }

    TEST(Maximum, TripleQueueTest2){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(6);
        p->Insert(4);
        p->Insert(1);
        ASSERT_EQ(6, p->Maximum());
        ASSERT_EQ(6, p->Maximum());
        ASSERT_EQ(4, p->getSize());
    }
}