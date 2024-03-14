#include <gtest/gtest.h>
#include "../../src/MaxHeap/MaxHeap.cpp"

typedef MaxHeap<int> Heap;

namespace {
    TEST(retrieveAndRemoveRoot, Test1_EmptyHeap){
        int A[] = {};

        auto heap = new Heap(A, 0);

        ASSERT_THROW(heap->retrieveAndRemoveRoot(), std::out_of_range);
    }

    TEST(retrieveAndRemoveRoot, Test1_Heap){
        int A[] = {3, 6, 9, 12};

        auto heap = new Heap(A, 4);

        ASSERT_EQ(3, heap->retrieveAndRemoveRoot());
        ASSERT_EQ(3, heap->getSize());
        ASSERT_EQ("[12,6,9]", heap->toString());
    }

    TEST(retrieveAndRemoveRoot, Test2_Heap){
        int A[] = {3, 6, 9, 12, 15, 18};

        auto heap = new Heap(A, 6);

        ASSERT_EQ(3, heap->retrieveAndRemoveRoot());
        ASSERT_EQ(5, heap->getSize());
    }

}