#include <iostream>

using namespace std;

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int *arr, int highIndex, int lowIndex) {
  int pivot = arr[highIndex];
  int left = lowIndex, right = highIndex;
  int temp;
  while (left < right) {
    while (arr[left] <= pivot && left < right) left++;
    while (arr[right] >= pivot && left < right) right--;
    swap(arr, left, right);
  }
  return left;
}

void quickSort(int *arr, int highIndex, int lowIndex = 0) {
  if (lowIndex >= highIndex) return;
  int partitionIndex = partition(arr, highIndex, lowIndex);
  swap(arr, highIndex, partitionIndex);
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
  quickSort(arr, size - 1);
  cout << "After Sorting: ";
  for (int i = 0; i < size; i++) cout << arr[i] << "\t";
  cout << endl;
}