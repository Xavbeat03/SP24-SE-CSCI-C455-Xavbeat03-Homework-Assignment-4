#include <gtest/gtest.h>

#include "../../src/AirportRecord/AirportRecord.cpp"

namespace {
    TEST(Getters, NormalRecord){
        AirportRecord a = AirportRecord(
                {"AES", "VIGRA", "ALESUND", "NORWAY", "62", "33", "37", "N", "6", "6", "36", "E", "69"});
        ASSERT_EQ("AES", *a.getCode());
        ASSERT_EQ("VIGRA", *a.getName());
        ASSERT_EQ("ALESUND", *a.getCity());
        ASSERT_EQ("NORWAY", *a.getCountry());
        ASSERT_EQ(62, *a.getLatitudeDegree());
        ASSERT_EQ(33, *a.getLatitudeMinutes());
        ASSERT_EQ(37, *a.getLatitudeSeconds());
        ASSERT_EQ("N", *a.getDirection());
        ASSERT_EQ(6, *a.getLongitudeDegree());
        ASSERT_EQ(6, *a.getLongitudeMinutes());
        ASSERT_EQ(36, *a.getLongitudeSeconds());
        ASSERT_EQ("E", *a.getLongitudeDirection());
        ASSERT_EQ(69, *a.getAltitude());
    }
}