#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        cout << "CMP " << l << " " << largest << endl;
        if (arr[l] > arr[largest]) largest = l;
    }

    if (r < n) {
        cout << "CMP " << r << " " << largest << endl;
        if (arr[r] > arr[largest]) largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        cout << "UPD " << i << " " << arr[i] << endl;
        cout << "UPD " << largest << " " << arr[largest] << endl;
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        cout << "UPD " << 0 << " " << arr[0] << endl;
        cout << "UPD " << i << " " << arr[i] << endl;
        heapify(arr, i, 0);
    }
}

int main(int argc, char* argv[]) {
    vector<int> arr;
    if (argc > 1) {
        int n = atoi(argv[1]);
        srand(42);
        for (int i = 0; i < n; i++) arr.push_back(rand() % 600 + 1);
    } else {
        arr = {120, 350, 50, 560, 200, 410, 80, 5, 290, 480, 150, 310, 220, 600, 100, 450, 30, 520, 180, 390};
    }
    heapSort(arr);
    return 0;
}
