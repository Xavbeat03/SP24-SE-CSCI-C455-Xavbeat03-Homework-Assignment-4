#include <gtest/gtest.h>

#include "../../src/PriorityQueue/PriorityQueue.h"

namespace {
    TEST(Insert, TEST1_EMPTYQUEUE){
        PriorityQueue<int>* p;
        std::tuple<int, int> t = {3, 3};
        p->Insert(t);
        ASSERT_EQ(3, std::get<1>(p->Extract_Max()));
    }

    TEST(Insert, TEST2_EMPTYQUEUE){
        PriorityQueue<int>* p;
        std::tuple<int, int> t = {3, 3};
        std::tuple<int, int> t2 = {4, 4};
        p->Insert(t);
        p->Insert(t2);
        ASSERT_EQ(4, std::get<1>(p->Extract_Max()));
    }

    TEST(Insert, TEST3_EMPTYQUEUE){
        PriorityQueue<int>* p;
        std::tuple<int, int> t = {3, 3};
        std::tuple<int, int> t2 = {4, 4};
        std::tuple<int, int> t3 = {2, 2};
        p->Insert(t);
        p->Insert(t2);
        p->Insert(t3);
        ASSERT_EQ(4, std::get<1>(p->Extract_Max()));
    }
}