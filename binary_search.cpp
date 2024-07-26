#include <iostream>
#include <vector>
#include "QuickSort.h"

int binarySearch(const std::vector<int>& vec, int target) {
    int left = 0;
    int right = vec.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {
            return mid;
        } else if (vec[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> vec = {4, 3, 6, 2, 9, 5, 3, 10, 2, 19, 20, 2, 13, 19, 20, 11};
    QuickSort::quickSort(vec, 0, vec.size());
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << binarySearch(vec, 20) << std::endl;
    std::cout << std::endl;
    return 0;
}