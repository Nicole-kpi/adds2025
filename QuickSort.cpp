#include "QuickSort.h"
#include <utility>

std::vector<int> QuickSort::sort(std::vector<int> list) {
    if (list.size() > 1) quicksort(list, 0, static_cast<int>(list.size() - 1));
    return list;
}

void QuickSort::quicksort(std::vector<int>& a, int left, int right) {
    if (left >= right) return;
    int p = partition(a, left, right);
    quicksort(a, left, p - 1);
    quicksort(a, p + 1, right);
}

int QuickSort::partition(std::vector<int>& a, int left, int right) {
    int len = right - left + 1;
    int pivotIdx = (len >= 3) ? (left + 2) : right;
    int pivotVal = a[pivotIdx];


    std::swap(a[pivotIdx], a[right]);
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (a[j] <= pivotVal) {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[right]);
    return i + 1;
}
