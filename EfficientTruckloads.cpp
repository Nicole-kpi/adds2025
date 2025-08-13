#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int n, int L) {
    if (n <= L) return 1;

    std::uint64_t k = makeKey(n, L);
    std::unordered_map<std::uint64_t, int>::iterator it = memo.find(k);
    if (it != memo.end()) {
        return it->second;
    }

    int left  = n / 2;       // floor(n/2)
    int right = n - left;    // ceil(n/2)
    int ans = numTrucks(left, L) + numTrucks(right, L);

    memo[k] = ans;
    return ans;
}

