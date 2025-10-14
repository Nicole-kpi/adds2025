// klargest.cpp
#include <vector>
#include <queue>
#include <functional>
#include <climits>

int kth_largest(std::vector<int> values, int k) {
    if (k <= 0 || k > (int)values.size()) return INT_MIN;
     
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int x : values) {
        if ((int)pq.size() < k) {
            pq.push(x);
        } else if (x > pq.top()) {
            pq.pop();
            pq.push(x);
        }
    }
    return pq.top();
}
