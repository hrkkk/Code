#include <iostream>
#include <vector>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<int>& vec, int start, int end) {
    int baseline = vec[start];
    int left = start + 1, right = end - 1;
    while (left <= right) {
        if (vec[left] > baseline) {
            swap(vec[left], vec[right]);
            right--;
        } else {
            left++;
        }
    }
    swap(vec[start], vec[left - 1]);
    return left - 1;
}

void quickSort(std::vector<int>& vec, int start, int end) {
    if (end - start > 1) {
        // 分区
        int mid = partition(vec, start, end);
        // 递归左右子序列
        quickSort(vec, start, mid);
        quickSort(vec, mid + 1, end);
    }
}

int main()
{
    std::vector<int> vec = {4, 3, 6, 2, 9, 5, 3, 10, 2, 19, 20, 2, 13, 19, 20, 11};
    quickSort(vec, 0, vec.size());
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}