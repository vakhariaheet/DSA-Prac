#include <iostream>
using namespace std;

int search(int arr[], int length, int val) {
  for (int i = 0; i < length; i++) {
    if (arr[i] == val) {
      return i;
    }
  }
  return -1;
}

int main() {
  int length;
  cout << "Enter the length of the array: ";
  cin >> length;
  int arr[length];
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }
  int val;
  cout << "Enter the value to be searched: ";
  cin >> val;
  int result = search(arr, length, val);
  if (result == -1) {
    cout << "Element not found" << endl;
  } else {
    cout << "Element found at index " << result << endl;
  }
  return 0;
}