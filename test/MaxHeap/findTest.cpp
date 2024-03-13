#include <gtest/gtest.h>

#include "../../src/MaxHeap/MaxHeap.cpp"

namespace {
    TEST(find,TEST1_Empty) {
        int A[] = {};

        auto heap = new MaxHeap(A, 0);

        ASSERT_THROW(heap->find(0), std::out_of_range);

    }

    TEST(find, TEST1_Single){
        int A[] = {1};

        auto heap = new MaxHeap(A, 1);

        ASSERT_EQ(0, heap->find(1));
    }

    TEST(find, TEST1_SingleNotWithin){
        int A[] = {1};

        auto heap = new MaxHeap(A, 1);

        ASSERT_EQ(-1, heap->find(0));
    }

    TEST(find, TEST1_TenWithin){
        int A[] = {1,2,3,4,5,6,7,8,9,10};

        auto heap = new MaxHeap(A, 10);

        ASSERT_EQ(2, heap->find(3));
    }

    TEST(find, TEST2_TenWithin){
        int A[] = {1,2,3,4,5,6,7,8,9,10};

        auto heap = new MaxHeap(A, 10);

        ASSERT_EQ(9, heap->find(10));
    }

    TEST(find, TEST1_TenNotWithin){
        int A[] = {1,2,3,4,5,6,7,8,9,10};

        auto heap = new MaxHeap(A, 10);

        ASSERT_EQ(-1, heap->find(11));
    }
}