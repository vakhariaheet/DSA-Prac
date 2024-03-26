#include <iostream>

using namespace std;
void merge(int *arr, int lowIndex, int highIndex) {
  int mid = (lowIndex + highIndex) / 2;
  int leftHalfArrSize = mid - lowIndex + 1;
  int rightHalfArrSize = highIndex - mid;
  int leftHalf[leftHalfArrSize], rightHalf[rightHalfArrSize];
  for (int i = 0; i < leftHalfArrSize; i++) leftHalf[i] = arr[lowIndex + i];
  for (int i = 0; i < rightHalfArrSize; i++) rightHalf[i] = arr[mid + 1 + i];
  int i = 0, j = 0, k = lowIndex;
  while (i < leftHalfArrSize && j < rightHalfArrSize) {
    if (leftHalf[i] <= rightHalf[j]) {
      arr[k++] = leftHalf[i++];
    } else {
      arr[k++] = rightHalf[j++];
    }
  }
  while (i < leftHalfArrSize) arr[k++] = leftHalf[i++];

  while (j < rightHalfArrSize) arr[k++] = rightHalf[j++];
}

void mergeSort(int *arr, int lowIndex, int highIndex) {
  if (lowIndex >= highIndex) {
    return;
  };
  int mid = (lowIndex + highIndex) / 2;
  mergeSort(arr, lowIndex, mid);
  mergeSort(arr, mid + 1, highIndex);

  merge(arr, lowIndex, highIndex);
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
  mergeSort(arr, 0, size - 1);
  cout << endl;
  cout << "After Sorting: ";
  for (int i = 0; i < size; i++) cout << arr[i] << "\t";
  cout << endl;

  return 0;
}