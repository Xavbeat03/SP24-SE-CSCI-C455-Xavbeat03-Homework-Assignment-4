cmake_minimum_required(VERSION 3.28)
project(SP24_SE_CSCI_C455_Xavbeat03_Homework_Assignment_4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        src/MaxHeap/MaxHeap.cpp
        src/PriorityQueue/PriorityQueue.h
        src/test/MaxHeap/toString.cpp
        src/test/MaxHeap/getSize.cpp
        src/test/MaxHeap/getHeap_Size.cpp
        src/test/MaxHeap/Heapsort.cpp
        src/test/MaxHeap/Build_Max_Heap.cpp
        src/test/MaxHeap/Max_Heapify.cpp
        src/test/MaxHeap/insert.cpp
        src/test/MaxHeap/remove.cpp
        src/test/MaxHeap/retrieveAndRemoveRoot.cpp
        src/test/MaxHeap/find.cpp
        src/test/MaxHeap/insert.cpp
)

target_link_libraries(
        MaxHeap.cpp
        gtest_discover_tests(MaxHeap.cpp)
)

