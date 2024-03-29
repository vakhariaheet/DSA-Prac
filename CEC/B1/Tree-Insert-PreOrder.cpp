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
 public:
  Node* root;
  BinaryTree() { root = NULL; }
  Node* createNode() {
    Node* newNode = new Node();
    cout << "Enter a number: ";
    cin >> newNode->data;
    return newNode;
  }

 public:
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

  void preOrder(Node* ptr) {
    if (ptr == NULL) return;
    cout << ptr->data << " ";
    preOrder(ptr->left);
    preOrder(ptr->right);
  }
};

int displayMenu() {
  int choice;
  cout << "===============================================" << endl;
  cout << "1. Insert a value" << endl;
  cout << "2. Display" << endl;
  cout << "3. Exit" << endl;
  cout << "===============================================" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main() {
  BinaryTree tree;
  while (true) {
    switch (displayMenu()) {
      case 1:
        tree.insertValue();
        break;
      case 2:
        tree.preOrder(tree.root);
        cout << endl;
        break;
      case 3:
        cout << "Exiting..." << endl;
        return 0;
      default:
        cout << "Invalid choice" << endl;
    }
  }
  return 0;
}