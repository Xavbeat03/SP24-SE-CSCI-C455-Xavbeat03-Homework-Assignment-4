#include <gtest/gtest.h>

#include "../../src/PriorityQueue/PriorityQueue.cpp"

typedef PriorityQueue<int> pqueue;

namespace {
    TEST(ExtractMax, EmptyQueueTest1){
        auto* p = new pqueue();
        ASSERT_THROW(p->Extract_Max(), std::out_of_range);
    }

    TEST(ExtractMax, EmptyQueueTest2){
        auto* p = new pqueue();
        p->Insert(3);
        ASSERT_EQ(3, p->Extract_Max());
        ASSERT_EQ(0, p->getSize());
    }

    TEST(ExtractMax, EmptyQueueTest3){
        auto* p = new pqueue();
        p->Insert(5);
        ASSERT_EQ(5, p->Extract_Max());
        ASSERT_EQ(0, p->getSize());
    }

    TEST(ExtractMax, SingleQueueTest1){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(7);
        ASSERT_EQ(7, p->Extract_Max());
        ASSERT_EQ(5, p->Extract_Max());
        ASSERT_EQ(0, p->getSize());


    }

    TEST(ExtractMax, SingleQueueTest2){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(3);
        ASSERT_EQ(5, p->Extract_Max());
        ASSERT_EQ(3, p->Extract_Max());
        ASSERT_EQ(0, p->getSize());

    }

    TEST(ExtractMax, DoubleQueueTest1){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(3);
        p->Insert(4);
        ASSERT_EQ(5, p->Extract_Max());
        ASSERT_EQ(4, p->Extract_Max());
        ASSERT_EQ(3, p->Extract_Max());
        ASSERT_EQ(0, p->getSize());

    }

    TEST(ExtractMax, DoubleQueueTest2){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(6);
        p->Insert(4);
        ASSERT_EQ(6, p->Extract_Max());
        ASSERT_EQ(5, p->Extract_Max());
        ASSERT_EQ(4, p->Extract_Max());
        ASSERT_EQ(0, p->getSize());

    }

    TEST(ExtractMax, TripleQueueTest1){
        auto* p = new pqueue();
        p->Insert(5);
        p->Insert(6);
        p->Insert(4);
        p->Insert(7);
        ASSERT_EQ(7, p->Extract_Max());
        ASSERT_EQ(6, p->Extract_Max());
        ASSERT_EQ(5, p->Extract_Max());
        ASSERT_EQ(4, p->Extract_Max());
        ASSERT_EQ(0, p->getSize());

    }

    TEST(ExtractMax, TripleQueueTest2) {
        auto *p = new pqueue();
        p->Insert(5);
        p->Insert(6);
        p->Insert(4);
        p->Insert(1);
        ASSERT_EQ(6, p->Extract_Max());
        ASSERT_EQ(5, p->Extract_Max());
        ASSERT_EQ(4, p->Extract_Max());
        ASSERT_EQ(1, p->Extract_Max());
        ASSERT_EQ(0, p->getSize());
    }
}