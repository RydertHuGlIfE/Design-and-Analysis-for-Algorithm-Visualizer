#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            cout << "CMP " << j << " " << j+1 << endl;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cout << "UPD " << j << " " << arr[j] << endl;
                cout << "UPD " << j+1 << " " << arr[j+1] << endl;
                swapped = true;
            }
        }
      
        if (!swapped)
            break;
    }
}

void printVector(const vector<int>& arr) {
    for (int num : arr)
        cout << " " << num;
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
    bubbleSort(arr);
    return 0;
}