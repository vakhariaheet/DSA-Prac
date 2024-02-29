#include <iostream>

using namespace std;

int linearSearch(int *arr, int size, int value) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) return i;
  }
  return -1;
}

int main() {
  int size;
  cout << "Enter size of the array: " ;
  cin >> size;
  int arr[size];
  cout << "Enter " << size << " elements: ";
  for (int i = 0; i < size; i++) cin >> arr[i];
  int val;
  cout << "Enter value to search: ";
  cin >> val;
  int idx = linearSearch(arr, size, val);
  if (idx == -1) {
    cout << "Element not found" << endl;
  } else {
    cout << "Element found at index " << idx << endl;
  }
  return 0;
}