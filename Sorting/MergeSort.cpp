#include <iostream>

using namespace std;
void merge(int *arr, int lowIndex, int highIndex) {
  int mid = (lowIndex + highIndex) / 2;
  int leftHalf[mid], rightHalf[highIndex - mid];
  for (int i = 0; i < mid; i++) leftHalf[i] = arr[i];
  for (int i = mid; i < highIndex; i++) rightHalf[i - mid] = arr[i];

  int leftHalfIndex = 0, rightHalfIndex = 0, newArrIndex = 0;
  while (leftHalfIndex < mid && rightHalfIndex < highIndex - mid) {
    if (arr[leftHalfIndex] <= rightHalf[rightHalfIndex]) {
      arr[newArrIndex] = leftHalf[leftHalfIndex];
      leftHalfIndex++;
    } else {
      arr[newArrIndex] = rightHalf[rightHalfIndex];
      rightHalfIndex++;
    }
    newArrIndex++;
  }

  while (leftHalfIndex < mid) {
    arr[newArrIndex] = leftHalf[leftHalfIndex];
    newArrIndex++;
    leftHalfIndex++;
  }

  while (rightHalfIndex < highIndex - mid) {
    arr[newArrIndex] = rightHalf[rightHalfIndex];
    newArrIndex++;
    rightHalfIndex++;
  }
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