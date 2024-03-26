#include <iostream>

using namespace std;

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int *arr, int highIndex, int lowIndex) {
  int pivot = arr[highIndex];  // Choose the last element as the pivot
  int i = lowIndex - 1;        // Index of smaller element

  for (int j = lowIndex; j < highIndex; j++) {
    // If current element is smaller than or equal to pivot
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[highIndex]);
  return i + 1;
}

void quickSort(int *arr, int highIndex, int lowIndex) {
  if (lowIndex >= highIndex) return;
  int partitionIndex = partition(arr, highIndex, lowIndex);
  quickSort(arr, partitionIndex - 1, lowIndex);
  quickSort(arr, highIndex, partitionIndex + 1);
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
  quickSort(arr, size - 1, 0);
  cout << "After Sorting: ";
  for (int i = 0; i < size; i++) cout << arr[i] << "\t";
  cout << endl;
}