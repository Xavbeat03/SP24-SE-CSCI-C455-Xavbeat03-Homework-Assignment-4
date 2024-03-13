#include <gtest/gtest.h>
#include "../../src/MaxHeap/MaxHeap.cpp"

namespace {
    TEST(Build_Max_Heap, Test1_EmptyHeap){
        int A[] = {};

        auto heap = new MaxHeap(A, 0);


        ASSERT_THROW(heap->Build_Max_Heap(), std::out_of_range);
    }

    TEST(Build_Max_Heap, Test1_SingleHeap){
        int A[] = {1};

        auto heap = new MaxHeap(A, 1);
        heap->Build_Max_Heap();

        ASSERT_EQ("[1]", heap->toString());
    }

    TEST(Build_Max_Heap, Test1_DoubleHeap){
        int A[] = {1,2};

        auto heap = new MaxHeap(A, 2);
        heap->Build_Max_Heap();

        ASSERT_EQ("[2,1]", heap->toString());
    }

    TEST(Build_Max_Heap, Test1_TripleHeap){
        int A[] = {1,2,3};

        auto heap = new MaxHeap(A, 3);
        heap->Build_Max_Heap();

        ASSERT_EQ("[3,2,1]", heap->toString());
    }

    TEST(Build_Max_Heap, Test1_QuadrupleHeap){
        int A[] = {1,2,3,4};

        auto heap = new MaxHeap(A, 4);
        heap->Build_Max_Heap();

        ASSERT_EQ("[4,2,3,1]", heap->toString());
    }

}