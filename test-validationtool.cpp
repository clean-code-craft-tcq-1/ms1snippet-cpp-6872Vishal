#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"

TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateCurrentreadings(socReadings, numOfSocReadings, SOC) == false);
}

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.03, 0.03, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateCurrentreadings(currentReadings, numOfCurReadings, Normal) == false);
}

TEST_CASE("Check for NULL pointer") {
  double* currentReadings = NULL;
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateCurrentreadings(currentReadings, numOfCurReadings, Normal) == true);
}

