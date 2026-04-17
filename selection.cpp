#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            cout << "CMP " << j << " " << min_idx << endl;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
        cout << "UPD " << min_idx << " " << arr[min_idx] << endl;
        cout << "UPD " << i << " " << arr[i] << endl;
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
    selectionSort(arr);
    return 0;
}