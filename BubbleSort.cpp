#include "BubbleSort.h"
#include <vector>

std::vector<int> BubbleSort::sort(std::vector<int> list) {
    if(list.size() < 2) return list;
    bool swapped = true;
    std::size_t n = list.size();

    while(swapped){
        swapped = false;
        for(std::size_t i = 1; i < n; ++i)
        {
            if(list[i] > list[i + 1])
            {
                std::swap(list[i], list[i + 1]);
                swapped = true;
            }
        }
        if (n > 0) --n; // Reduce the range for optimization
    }
        
    return list;
}