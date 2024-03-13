#include <gtest/gtest.h>
#include "../../src/MaxHeap/MaxHeap.cpp"

typedef MaxHeap<int> Heap;

namespace {
    TEST(Heapsort,TEST1_EmptyHeap){
        int A[] = {};

        auto heap = new Heap(A, 0);

        ASSERT_THROW(heap->Heapsort(), std::out_of_range);

    }

    TEST(Heapsort,TEST1_SingleHeap){
        int A[] = {1};

        auto heap = new Heap(A, 1);

        heap->Heapsort();
        ASSERT_EQ("[1]", heap->toString());
    }

    TEST(Heapsort,TEST1_FullHeap){
        int A[]={1,2,3,4,5,6};

        auto heap = new Heap(A, 6);

        heap->Heapsort();
        ASSERT_EQ("[1,2,3,4,5,6]", heap->toString());
    }

    TEST(Heapsort,TEST2_FullHeap){
        int A[]={7,2,3,4,5,6};

        auto heap = new Heap(A, 6);

        heap->Heapsort();
        ASSERT_EQ("[2,3,4,5,6,7]", heap->toString());
    }

    TEST(Heapsort,TEST3_FullHeap){
        int A[]={7,7,3,4,5,6};

        auto heap = new Heap(A, 6);

        heap->Heapsort();
        ASSERT_EQ("[3,4,5,6,7,7]", heap->toString());
    }
}