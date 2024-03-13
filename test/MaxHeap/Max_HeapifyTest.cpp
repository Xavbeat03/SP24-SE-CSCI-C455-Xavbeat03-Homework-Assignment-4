#include <gtest/gtest.h>
#include "../../src/MaxHeap/MaxHeap.cpp"

namespace {
    TEST(Max_Heapify, Test1_EmptyHeap){
        int A[] = {};

        auto heap = new MaxHeap(A, 0);

        ASSERT_THROW(heap->Max_Heapify(0), std::out_of_range);
    }

    TEST(Max_Heapify, Test1_Size1Heap){
        int A[] = {1};

        auto heap = new MaxHeap(A, 1);

        heap->Max_Heapify(0);

        ASSERT_EQ("[1]", heap->toString());
        ASSERT_EQ(1, heap->getSize());
    }

    TEST(Max_Heapify, Test1_NormalHeap){
        int A[] = {1, 2, 3, 4, 5, };

        auto heap = new MaxHeap(A, 5);

        heap->Max_Heapify(0);

        ASSERT_EQ("[3,2,1,4,5]", heap->toString());
        ASSERT_EQ(5, heap->getSize());
    }
}
