enum DeltaTypes = {Normal, SOC, Total_Deltas};

double MaxDelta[Total_Deltas] = {0.1 , 0.05};

bool difference_of_2nd_and_1stValue_greaterthan_3rd(double value, double nextValue, double maxDelta);

bool validateCurrentreadings(double* values, int numOfValues, int Which_Delta_Type);
