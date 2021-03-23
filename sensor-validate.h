enum DeltaTypes {Normal, SOC, Total_Deltas};

bool difference_of_2nd_and_1stValue_greaterthan_3rd(double value, double nextValue, double maxDelta);

bool validateCurrentreadings(double* values, int numOfValues, DeltaTypes Which_Delta_Type);
