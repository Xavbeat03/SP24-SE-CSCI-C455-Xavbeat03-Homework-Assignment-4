#include <gtest/gtest.h>

#include "../../src/MaxHeap/MaxHeap.cpp"

typedef MaxHeap<int> Heap;

namespace {
    TEST(getSize, Test1_EMPTY){
        int A[] = {};

        auto heap = new Heap(A, 0);

        ASSERT_EQ(heap->getSize(), 0);
    }

    TEST(getSize, Test1_Single){
        int A[] = {1};

        auto heap = new Heap(A, 1);

        ASSERT_EQ(heap->getSize(), 1);
    }

    TEST(getSize, Test1_Double){
        int A[] = {1,2};

        auto heap = new Heap(A, 2);

        ASSERT_EQ(heap->getSize(), 2);
    }


    TEST(getSize, Test1_Triple){
        int A[] = {1,2,3};

        auto heap = new Heap(A, 3);

        ASSERT_EQ(heap->getSize(), 3);
    }

    TEST(getSize, Test1_Sectuple){
        int A[] = {1,2,3,5,6,7,8};

        auto heap = new Heap(A, 6);

        ASSERT_EQ(heap->getSize(), 6);
    }


}
