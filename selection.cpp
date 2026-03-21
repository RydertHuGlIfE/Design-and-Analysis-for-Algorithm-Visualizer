#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 

    for (i = 0; i < n-1; i++){
        min_idx = i; 
        for (j = i+1; j < n; j++) {
            cout << "CMP " << j << " " << min_idx << endl;
            if (arr[j] < arr[min_idx]) {
                min_idx = j; 
                
            }
        }
        swap(&arr[min_idx], &arr[i]); 
        cout << "UPD " << min_idx << " " << arr[min_idx] << endl;
        cout << "UPD " << i << " " << arr[i] << endl;
    } 
} 


int main() 
{ 
    int arr[] = {120, 350, 50, 560, 200, 410, 80, 5, 290, 480, 150, 310, 220, 600, 100, 450, 30, 520, 180, 390};
    int n = sizeof(arr)/sizeof(arr[0]); 
    selectionSort(arr, n); 

    return 0; 
}