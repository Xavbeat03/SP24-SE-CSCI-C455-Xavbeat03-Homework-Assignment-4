#include <gtest/gtest.h>

#include "../../src/AirportRecord/AirportRecord.cpp"

namespace {
    TEST(conditionals, equalityTest1){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        ASSERT_TRUE(a==a);
    }

    TEST(conditionals, inequalityTest1){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        ASSERT_FALSE(a!=a);
    }

    TEST(conditionals, greaterThanTest1){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        ASSERT_FALSE(a>a);
    }

    TEST(conditionals, greaterThanTest2){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        AirportRecord b = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "70"});

        ASSERT_TRUE(b>a);
    }

    TEST(conditionals, greaterThanOrEqualTest1){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        AirportRecord b = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        ASSERT_TRUE(b>=a);
    }

    TEST(conditionals, greaterThanOrEqualTest2){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        AirportRecord b = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "68"});

        ASSERT_FALSE(b>=a);
    }

    TEST(conditionals, lessThanTest1){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        AirportRecord b = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "68"});

        ASSERT_TRUE(b<a);
    }

    TEST(conditionals, lessThanTest2){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        AirportRecord b = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "68"});

        ASSERT_FALSE(a<b);
    }

    TEST(conditionals, lessThanOrEqualTest1){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        AirportRecord b = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        ASSERT_FALSE(a<=b);
    }

    TEST(conditionals, lessThanOrEqualTest2){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});

        AirportRecord b = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "70"});

        ASSERT_FALSE(a<=b);
    }
}