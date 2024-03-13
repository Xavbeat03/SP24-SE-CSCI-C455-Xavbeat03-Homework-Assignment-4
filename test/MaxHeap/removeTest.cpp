#include <gtest/gtest.h>
#include "../../src/MaxHeap/MaxHeap.cpp"

namespace{
    TEST(Remove, Test1_RemoveFromEmpty){
        int A[] = {};

        auto heap = new MaxHeap(A, 0);

        ASSERT_THROW(heap->remove(0), std::out_of_range);
    }

    TEST(Remove, Test1_RemoveFromOne){
        int A[] = {2};

        auto heap = new MaxHeap(A, 1);

        heap->remove(0);

        ASSERT_EQ(0, heap->getSize());
        ASSERT_EQ("[]", heap->toString());
    }

    TEST(Remove, Test1_RemoveFromFilledHeap){
        int A[] = {2, 5, 12, 10};

        auto heap = new MaxHeap(A, 4);

        heap->remove(3);

        ASSERT_EQ("[12,10,2]", heap->toString());
        ASSERT_EQ(3, heap->getSize());
    }
    TEST(Remove, Test2_RemoveFromFilledHeap){
        int A[] = {2, 5, 12, 10};

        auto heap = new MaxHeap(A, 4);

        heap->remove(1);

        ASSERT_EQ("[12,5,2]", heap->toString());
        ASSERT_EQ(3, heap->getSize());
    }
}
