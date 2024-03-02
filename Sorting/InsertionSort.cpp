#include <iostream>

using namespace std;

void insertionSort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    int currentVal = arr[i];
    int j = i - 1;
    while (j > -1 && arr[j] > currentVal) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = currentVal;
  }
}

int main() {
  int size;
  cout << "Enter size of array: ";
  cin >> size;
  int arr[size];
  cout << "Enter " << size << " elements : ";
  for (int i = 0; i < size; i++) cin >> arr[i];
  cout << "Before Sorting: ";
  for (int i = 0; i < size; i++) cout << arr[i] << "\t";
  cout << endl;
  insertionSort(arr, size);
  cout << "After Sorting: ";
  for (int i = 0; i < size; i++) cout << arr[i] << "\t";
  cout << endl;
}