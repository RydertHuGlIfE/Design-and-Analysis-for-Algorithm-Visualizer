#include <iostream>
#include <vector>
#include <algorithm>

void swap(std::vector<int>& arr, int i, int j) {
    int temp = arr[static_cast<std::size_t>(i)];
    arr[static_cast<std::size_t>(i)] = arr[static_cast<std::size_t>(j)];
    arr[static_cast<std::size_t>(j)] = temp;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[static_cast<std::size_t>(high)];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[static_cast<std::size_t>(j)] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = static_cast<int>(arr.size());
    
    quickSort(arr, 0, n - 1);
    
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
    
    return 0;
}