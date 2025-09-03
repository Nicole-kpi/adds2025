#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "Sort.h"

class QuickSort : public Sort {
public:
    std::vector<int> sort(std::vector<int> list) override;

private:
    static void quicksort(std::vector<int>& a, int left, int right);
    static int partition(std::vector<int>& a, int left, int right);
};

#endif // QUICK_SORT_H
