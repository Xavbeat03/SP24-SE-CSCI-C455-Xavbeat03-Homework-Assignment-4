#include <gtest/gtest.h>
#include "../../src/MaxHeap/MaxHeap.cpp"

namespace {
    TEST(Max_Heapify, Test1_EmptyHeap){
        int A[] = {1};

        auto heap = new MaxHeap(A, 1);

        heap->remove(0);

        ASSERT_THROW(heap->Max_Heapify(0), std::out_of_range);
    }

    TEST(Max_Heapify, Test1_Size1Heap){
        int A[] = {1};

        auto heap = new MaxHeap(A, 1);


    }
}
