// RecursiveBinarySearch.cpp
#include "RecursiveBinarySearch.h"
#include <vector>
#include <cstddef>

namespace {
bool searchRange(const std::vector<int>& a, int x, std::size_t l, std::size_t r) {
    if (l > r) return false;
    std::size_t mid = l + (r - l) / 2;
    if (a[mid] == x) return true;
    if (x < a[mid]) {
        if (mid == 0) return false;          
        return searchRange(a, x, l, mid - 1);
    }
    return searchRange(a, x, mid + 1, r);
}
} 

bool RecursiveBinarySearch::search(const std::vector<int>& list, int x) {
    if (list.empty()) return false;
    return searchRange(list, x, 0, list.size() - 1);
}

bool search(const std::vector<int>& list, int x) {
    return RecursiveBinarySearch::search(list, x);
}
