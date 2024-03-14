#include <gtest/gtest.h>
#include "../../src/MaxHeap/MaxHeap.cpp"

typedef MaxHeap<int> Heap;

namespace {

    TEST(ReplaceAt, Test1_EmptyHeap){
        int A[] = {};

        auto heap = new Heap(A, 0);

        ASSERT_THROW(heap->replaceAt(0, 15), std::out_of_range);
    }

    TEST(ReplaceAt, Test1_SingleHeap){
        int A[] = {1};

        auto heap = new Heap(A, 1);

        heap->replaceAt(0, 4);
        ASSERT_EQ("[4]", heap->toString());
        ASSERT_EQ(1, heap->getSize());
    }

    TEST(ReplaceAt, Test2_SingleHeap){
        int A[] = {1};

        auto heap = new Heap(A, 1);

        heap->replaceAt(0, 5);
        ASSERT_EQ("[5]", heap->toString());
        ASSERT_EQ(1, heap->getSize());
    }

    TEST(ReplaceAt, Test1_DoubleHeap){
        int A[] = {1,2};

        auto heap = new Heap(A, 2);

        heap->replaceAt(0, 5);
        ASSERT_EQ("[5,2]", heap->toString());
        ASSERT_EQ(2, heap->getSize());
    }

    TEST(ReplaceAt, Test1_SectupleHeap){
        int A[] = {1, 2, 3, 4, 5, 6, 7};

        auto heap = new Heap{A, 7};

        heap->Build_Max_Heap();

        heap->replaceAt(5, 8);

        ASSERT_EQ("[8,5,7,4,2,3,6]", heap->toString());
    }

}