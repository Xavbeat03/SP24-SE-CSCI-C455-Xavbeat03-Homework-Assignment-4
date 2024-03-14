#include <gtest/gtest.h>
#include "../../src/MaxHeap/MaxHeap.cpp"

typedef MaxHeap<int> Heap;
namespace {
    TEST(Insert, TEST1_EmptyHeap){
        int A[] = {};

        auto heap = new Heap(A, 0);

        heap->insert(1);

        ASSERT_EQ("[1]", heap->toString());
        ASSERT_EQ(1, heap->getSize());
    }

    TEST(Insert, TEST1_SingleHeap){
        int A[] = {1};
        auto heap = new Heap(A, 1);

        heap->insert(1);

        ASSERT_EQ("[1,1]", heap->toString());
        ASSERT_EQ(2, heap->getSize());
    }

    TEST(Insert, TEST2_SingleHeap){
        int A[] = {1};
        auto heap = new Heap(A, 1);

        heap->insert(2);

        ASSERT_EQ("[2,1]", heap->toString());
        ASSERT_EQ(2, heap->getSize());
    }

    TEST(Insert, TEST3_SingleHeap){
        int A[] = {1};
        auto heap = new Heap(A, 1);

        heap->insert(0);

        ASSERT_EQ("[1,0]", heap->toString());
        ASSERT_EQ(2, heap->getSize());
    }

    TEST(Insert, TEST1_BigHeap){
        int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
        auto heap = new Heap(A, 8);

        heap->insert(5);

        ASSERT_EQ("[5,1,3,2,5,6,7,8,4]", heap->toString());
        ASSERT_EQ(9, heap->getSize());
    }
}