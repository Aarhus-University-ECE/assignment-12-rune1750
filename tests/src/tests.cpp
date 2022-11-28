#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.h"
#include <stdbool.h>

// Test cases
TEST_CASE("(d)")
{// checks if setting different values of time works
    duration test(10);
    REQUIRE(test.getDuration() == 10);
    duration test2(20);
    REQUIRE(test2.getDuration() == 20);
}

TEST_CASE("(e)")
{// checks if tick adds 1 to time
    duration test(39);
    test.tick();
    REQUIRE(test.getDuration() == 40);
}

TEST_CASE("(f)")
{// tests if tick adds the input to time
    duration test(10);
    test.tick(100);
    REQUIRE(test.getDuration() == 110);
    test.tick(10);
    REQUIRE(test.getDuration() == 120);
}

TEST_CASE("(g)")
{// checks if setting the alarm works
    duration test(10);
    test.setAlarm(30);
    REQUIRE(test.tick(20) == true);
    test.setAlarm(60);
    REQUIRE(test.tick(20) == false);
}

TEST_CASE("(h)")
{// Checks setting alarm in the past. 
//program should print "Alarms can not be set in the past"
    duration test(20);
    test.setAlarm(19);
}

TEST_CASE("(i)")
{// Checks if implementation of the "checkAndUpdateAlarm" method works in both tick methods. 
    duration test(20);
    test.setAlarm(30);
    REQUIRE(test.tick(5) == false);
    
    duration test2(20);
    test2.setAlarm(30);
    REQUIRE(test2.tick(10) == true);

    duration test3(20);
    test3.setAlarm(22);
    REQUIRE(test3.tick() == false);
    
    duration test4(20);
    test4.setAlarm(21);
    REQUIRE(test4.tick() == true);
}