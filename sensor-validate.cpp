#include "sensor-validate.h"
//difference_of_NextandCurrentValue_greaterthan_precision
//difference_of_2nd_and_1stValue_greaterthan_3rd
bool difference_of_2nd_and_1stValue_greaterthan_3rd(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return true;
  }
  return false;
}

// bool validateSOCreadings(double* values, int numOfValues) {
//   int lastButOneIndex = numOfValues - 1;
//   for(int i = 0; i < lastButOneIndex; i++) {
//     if(difference_of_2nd_and_1stValue_greaterthan_3rd(values[i], values[i + 1], 0.05)) {
//       return false;
//     }
//   }
//   return true;
// }

// bool validateCurrentreadings(double* values, int numOfValues) {
//   int lastButOneIndex = numOfValues - 1;
//   for(int i = 0; i < lastButOneIndex; i++) {
//     if(difference_of_2nd_and_1stValue_greaterthan_3rd(values[i], values[i + 1], 0.1)) {
//       return false;
//     }
//   }
//   return true;
// }

bool validateCurrentreadings(double* values, int numOfValues,DeltaTypes Which_Delta_Type) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(difference_of_2nd_and_1stValue_greaterthan_3rd(values[i], values[i + 1], MaxDelta[Which_Delta_Type])) {
      return false;
    }
  }
  return true;
}
