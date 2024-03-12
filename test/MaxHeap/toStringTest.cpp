#include <gtest/gtest.h>
#include "../../src/MaxHeap/MaxHeap.cpp"

namespace {
    TEST(toString, Test1_EmptyHeap){
        int A[] = {};

        auto heap = new MaxHeap(A, 0);
        EXPECT_EQ("[]", heap->toString());
    }
}