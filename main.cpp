// main.cpp
#include <iostream>
#include <vector>
#include <sstream>
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cout << "false\n";
        return 0;
    }

    std::istringstream iss(line);
    std::vector<int> nums;
    int x;
    while (iss >> x) nums.push_back(x);

    QuickSort qs;
    std::vector<int> sorted = qs.sort(nums);

    // Binary search for 1
    bool hasOne = RecursiveBinarySearch::search(sorted, 1);

    std::cout << (hasOne ? "true" : "false");
    for (std::size_t i = 0; i < sorted.size(); ++i) {
        std::cout << ' ' << sorted[i];
    }
    std::cout << '\n';
    return 0;
}
