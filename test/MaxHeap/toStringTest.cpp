#include <gtest/gtest.h>
#include "../../src/MaxHeap/MaxHeap.cpp"

namespace {
    TEST(toString, Test1_EmptyHeap){
        int A[] = {};

        auto heap = new MaxHeap(A, 0);
        EXPECT_EQ("[]", heap->toString());
    }

    TEST(toString, Test1_FilledHeap){
        int A[] = {1, 2, 3, 4, 5, 6, 7, 8};

        auto heap = new MaxHeap(A, 8);
        heap->Heapsort();
        EXPECT_EQ("[1,2,3,4,5,6,7,8]", heap->toString());

    }

}