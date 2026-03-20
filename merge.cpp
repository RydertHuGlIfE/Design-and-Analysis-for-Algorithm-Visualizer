#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        std::cout << "CMP " << (left + i) << " " << (mid + 1 + j) << std::endl;

        if (L[i] <= R[j]) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        std::cout << "UPD " << k << " " << arr[k] << std::endl;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i++];
        std::cout << "UPD " << k << " " << arr[k] << std::endl;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j++];
        std::cout << "UPD " << k << " " << arr[k] << std::endl;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> arr = {120, 350, 50, 560, 200, 410, 80, 5, 290, 480, 150, 310, 220, 600, 100, 450, 30, 520, 180, 390};
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    return 0;
}