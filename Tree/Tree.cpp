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
};