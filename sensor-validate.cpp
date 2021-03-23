#include "sensor-validate.h"

double DeltaValue[Total_Deltas] = {0.1 , 0.05};

bool difference_of_2nd_and_1stValue_greaterthan_3rd(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return true;
  }
  return false;
}

bool validateCurrentreadings(double* values, int numOfValues,DeltaTypes Which_Delta_Type) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0;numOfValues != 0,i < lastButOneIndex; i++) {
    if(difference_of_2nd_and_1stValue_greaterthan_3rd(values[i], values[i + 1], DeltaValue[Which_Delta_Type])) {
      return false;
    }
  }

  return true;
}
