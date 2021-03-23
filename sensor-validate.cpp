#include "sensor-validate.h"

double DeltaValue[Total_Deltas] = {0.1 , 0.05};

bool difference_of_2nd_and_1stValue_greaterthan_3rd(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return true;
  }
  return false;
}

bool Delta_Deviation_Occured(double* values_provided, int LastIndex, double Delta_Used)
{
  for(int i = 0;numOfValues != 0,i < LastIndex; i++) {
    if(difference_of_2nd_and_1stValue_greaterthan_3rd(values_provided[i], values_provided[i + 1], Delta_Used) ) {
      return true;
    }
  }
  return false;
}

bool validateCurrentreadings(double* values, int numOfValues,DeltaTypes Which_Delta_Type) {

  if(numOfValues != 0)
  {
    int lastButOneIndex = numOfValues - 1;
      if(Delta_Deviation_Occured(values[0], lastButOneIndex, DeltaValue[Which_Delta_Type])) {
        return false;
    }
  }
  return true;
}
