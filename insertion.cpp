#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
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
int main()
{
    int arr[] = {120, 350, 50, 560, 200, 410, 80, 5, 290, 480, 150, 310, 220, 600, 100, 450, 30, 520, 180, 390};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    return 0;
}