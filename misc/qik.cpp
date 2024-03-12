#include <iostream>

using namespace std;

void swap(int *arr, int index1, int index2) {
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

int partition(int *arr, int pivot, int lowIndex, int highIndex) {
  int left = lowIndex;
  int right = highIndex;
  while (left < right) {
    while (arr[left] <= pivot && left < right) left++;
    while (arr[right] >= pivot && left < right) right--;
    swap(arr, left, right);
  }
  return left;
}

void quickSort(int *arr, int lowIndex, int highIndex) {
  if (lowIndex >= highIndex) return;
  int pivot = arr[highIndex];
  int partitionIndex = partition(arr, pivot, lowIndex, highIndex);
  swap(arr, partitionIndex, highIndex);
  quickSort(arr, lowIndex, partitionIndex - 1);
  quickSort(arr, partitionIndex + 1, highIndex);
}

int main() {
  int size;
  cout << "Enter a size of arr:";
  cin >> size;
  int arr[size];
  cout << "Enter " << size << " numbers:";
  for (int i = 0; i < size; i++) cin >> arr[i];
  cout << "Before Sorting";
  for (int i = 0; i < size; i++) cout << arr[i] << "\t";
  cout << endl;
  quickSort(arr, 0, size - 1);
  cout << "After Sorting";
  for (int i = 0; i < size; i++) cout << arr[i] << "\t";
  cout << endl;
}