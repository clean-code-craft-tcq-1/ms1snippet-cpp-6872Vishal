#include "sensor-validate.h"

#define ZERO  ((int)0)

double DeltaValue[Total_Deltas] = {0.1 , 0.05};

bool difference_of_2nd_and_1stValue_greaterthan_3rd(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return true;
  }
  return false;
}

bool Delta_Deviation_Occured(double* values_provided, int LastValueIndex, double Delta_Used)
{
  for(int i = 0;i < LastValueIndex; i++) {
    if(difference_of_2nd_and_1stValue_greaterthan_3rd(values_provided[i], values_provided[i + 1], Delta_Used) ) {
      return true;
    }
  }
  return false;
}

bool validateCurrentreadings(double* values, int numOfValues,DeltaTypes Which_Delta_Type) {

  if(values != NULL)
  {
    int lastButOneIndex = numOfValues - 1;
      if(Delta_Deviation_Occured(&values[ZERO], lastButOneIndex, DeltaValue[Which_Delta_Type])) {
        return false;
    }
  }
  return true;
}
