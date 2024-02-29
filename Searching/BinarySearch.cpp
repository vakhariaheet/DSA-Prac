#include <iostream>

using namespace std;

int binarySearch(int *arr, int size, int val) {
  int mid = size / 2;
  int start = 0;
  int end = size - 1;
  while (start <= end) {
    if (arr[mid] == val) return mid;
    if (arr[mid] > val) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
    mid = (start + end) / 2;
  }
  return -1;
}

int main() {
  int size;
  cout << "Enter size of the array: ";
  cin >> size;
  int arr[size];
  cout << "Enter " << size << " elements: ";
  for (int i = 0; i < size; i++) cin >> arr[i];
  int val;
  cout << "Enter value to search: ";
  cin >> val;
  int idx = binarySearch(arr, size, val);
  if (idx == -1) {
    cout << "Element not found" << endl;
  } else {
    cout << "Element found at index " << idx << endl;
  }
  return 0;
}
