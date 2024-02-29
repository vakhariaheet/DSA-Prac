#include <iostream>

using namespace std;

int search(int arr[], int length, int val) {
  int low = 0, high = length - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == val) {
      return mid;
    } else if (arr[mid] < val) {
      low = mid + 1;
    } else {
      high = mid - 1;
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
