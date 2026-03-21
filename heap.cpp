#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;
        cout << "CMP " << l << " " << largest << endl;

    if (r < n && arr[r] > arr[largest])
        largest = r;
        cout << "CMP " << r << " " << largest << endl;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        cout << "UPD " << i << " "  << arr[i] << endl;
        cout << "UPD " << largest << " " << arr[largest] << endl;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        cout << "UPD " << 0 << " " << arr[0] << endl;
        cout << "UPD " << i << " " << arr[i] << endl;
        heapify(arr, i, 0);
    }
    }
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program
int main()
{
    int arr[] = {120, 350, 50, 560, 200, 410, 80, 5, 290, 480, 150, 310, 220, 600, 100, 450, 30, 520, 180, 390};
    int n = sizeof(arr) / sizeof(arr[0]);
     for(int i=n/2 -1;i>=0;i--){
       heapify(arr,n,i);
   }
  
    heapSort(arr, n);
    
  return 0;}
