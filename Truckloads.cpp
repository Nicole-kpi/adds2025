#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize) {
    // 基本情况：这堆能直接上车
    if (numCrates <= loadSize) return 1;

    // 对半分：奇数时一堆多 1 个
    int left  = numCrates / 2;        // floor(n/2)
    int right = numCrates - left;     // ceil(n/2)

    // 递归计算左右两堆需要的车数
    return numTrucks(left, loadSize) + numTrucks(right, loadSize);
}
