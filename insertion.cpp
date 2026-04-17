#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            cout << "CMP " << j << " " << (j + 1) << endl;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                cout << "UPD " << j + 1 << " " << arr[j + 1] << endl;
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        if (j + 1 != i) {
            cout << "UPD " << j + 1 << " " << arr[j + 1] << endl;
        }
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
    insertionSort(arr);
    return 0;
}