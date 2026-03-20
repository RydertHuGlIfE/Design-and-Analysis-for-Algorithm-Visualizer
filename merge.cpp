#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(static_cast<std::size_t>(n1));
    std::vector<int> R(static_cast<std::size_t>(n2));

    for (int i = 0; i < n1; i++)
        L[static_cast<std::size_t>(i)] = arr[static_cast<std::size_t>(left + i)];
    for (int j = 0; j < n2; j++)
        R[static_cast<std::size_t>(j)] = arr[static_cast<std::size_t>(mid + 1 + j)];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        // REPORT COMPARE
        std::cout << "CMP " << (left + i) << " " << (mid + 1 + j) << std::endl;

        if (L[static_cast<std::size_t>(i)] <= R[static_cast<std::size_t>(j)]) {
            arr[static_cast<std::size_t>(k)] = L[static_cast<std::size_t>(i)];
            // REPORT UPDATE
            std::cout << "UPD " << k << " " << arr[static_cast<std::size_t>(k)] << std::endl;
            i++;
        } else {
            arr[static_cast<std::size_t>(k)] = R[static_cast<std::size_t>(j)];
            // REPORT UPDATE
            std::cout << "UPD " << k << " " << arr[static_cast<std::size_t>(k)] << std::endl;
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[static_cast<std::size_t>(k)] = L[static_cast<std::size_t>(i)];
        // REPORT UPDATE
        std::cout << "UPD " << k << " " << arr[static_cast<std::size_t>(k)] << std::endl;
        i++;
        k++;
    }

    while (j < n2) {
        arr[static_cast<std::size_t>(k)] = R[static_cast<std::size_t>(j)];
        // REPORT UPDATE
        std::cout << "UPD " << k << " " << arr[static_cast<std::size_t>(k)] << std::endl;
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> arr = {120, 350, 50, 560, 200, 410, 80, 5, 290, 480, 150, 310, 220, 600, 100, 450, 30, 520, 180, 390};
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}