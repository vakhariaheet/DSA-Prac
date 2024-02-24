// Linear Search
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

// Tree Search
#include <iostream>

using namespace std;

/**
 * @brief Node class represents a node in a binary tree.
 *
 * It contains an integer data value and pointers to its left and right child
 * nodes.
 */
class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node() { left = right = NULL; }
};

class BinaryTree {
  Node* root;

  Node* createNode() {
    Node* newNode = new Node();
    cout << "Enter a number: ";
    cin >> newNode->data;
    return newNode;
  }

 public:
  BinaryTree() { root = NULL; }
  void insertValue() {
    if (root == NULL) {
      root = createNode();
      return;
    }
    Node* newNode = createNode();
    Node* newNodeParent = root;
    Node* ptr = root;
    while (ptr != NULL) {
      newNodeParent = ptr;
      if (ptr->data > newNode->data)
        ptr = ptr->right;
      else
        ptr = ptr->left;
    }
    if (newNodeParent->data > newNode->data)
      newNodeParent->right = newNode;
    else
      newNodeParent->left = newNode;
  }

  int search(int value) {
    Node* ptr = root;
    while (ptr != NULL) {
      if (ptr->data == value) return 1;
      if (ptr->data > value)
        ptr = ptr->right;
      else
        ptr = ptr->left;
    }
    return 0;
  }
};

int displayMenu() {
  int choice;
  cout << "===============================================" << endl;
  cout << "1. Insert a value" << endl;
  cout << "2. Search for a value" << endl;
  cout << "3. Exit" << endl;
  cout << "===============================================" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main() {
  BinaryTree tree;
  int choice;
  do {
    choice = displayMenu();
    switch (choice) {
      case 1:
        tree.insertValue();
        break;
      case 2:
        int value;
        cout << "Enter a value to search: ";
        cin >> value;
        if (tree.search(value))
          cout << "Value found" << endl;
        else
          cout << "Value not found" << endl;
        break;
      case 3:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice" << endl;
    }
  } while (choice != 3);
  return 0;
}