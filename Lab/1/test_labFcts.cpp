/*
*   Alp Deniz Senyurt
*   100342433
*   CPSC2150 - W02
*/

#include <iostream>
#include "labFcts.h"

int main() {
   const int N = 1;
   int A[N];
   A[0] = 11;
   int x = A[0];
   if (search(x, A, N)) {
      std::cout << "found " << x << " in A as expected\n";
   }
   else {
      std::cout << "ERROR: failed to find " << x << " in A\n";
   }
   x = 7;
   if (search(x, A, N)) {
      std::cout << "ERROR: found " << x << " in A\n";
   }
   else {
      std::cout << "did not find " << x << " in A as expected\n";
   }
   return 0;
}
