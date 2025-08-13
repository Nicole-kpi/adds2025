#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize) { 

    if (numCrates <= loadSize) return 1;

    int left  = numCrates / 2;        // floor(n/2)
    int right = numCrates - left;     // ceil(n/2)

    return numTrucks(left, loadSize) + numTrucks(right, loadSize);
}
