#include <iostream>
#include <vector>
#include <algorithm>

void swap(std::vector<int>& arr, int i, int j) {
    if (j==1) return;

    int temp = arr[static_cast<std::size_t>(i)];
    arr[static_cast<std::size_t>(i)] = arr[static_cast<std::size_t>(j)];
    arr[static_cast<std::size_t>(j)] = temp;


    //report kro 
    std::cout << "UPD " << i << " " << arr[static_cast<size_t>(i)] << std::endl;
    std::cout << "UPD " << j << " " << arr[static_cast<size_t>(j)] << std::endl;

}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[static_cast<size_t>(high)];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        std::cout << "CMP " << j << " " << high << std::endl;
        if (arr[static_cast<size_t>(j)] < pivot) {
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
    std::vector<int> arr = {120, 350, 50, 560, 200, 410, 80, 5, 290, 480, 150, 310, 220, 600, 100, 450, 30, 520, 180, 390};
    int n = static_cast<int>(arr.size());
    
    quickSort(arr, 0, n - 1);
    
    return 0;
}