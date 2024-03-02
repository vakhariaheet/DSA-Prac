#include <iostream>

using namespace std;

void selectionSort(int *arr, int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
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
  selectionSort(arr, size);
  cout << "After Sorting: ";
  for (int i = 0; i < size; i++) cout << arr[i] << "\t";
  cout << endl;
}