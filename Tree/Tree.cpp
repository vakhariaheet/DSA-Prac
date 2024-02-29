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

/**
 * @brief BinaryTree class represents a binary tree.
 * 
 * It contains a pointer to the root node of the tree and methods to insert a
 * value into the tree and to traverse the tree in preorder, inorder, and
 * postorder.
 * 
 * The tree is implemented as a binary search tree, so the values are inserted
 * in such a way that the left child of a node contains a value less than the
 * node's value, and the right child contains a value greater than the node's
 * value.
 * 
*/
class BinaryTree {
  Node* createNode() {
    Node* newNode = new Node();
    cout << "Enter a number: ";
    cin >> newNode->data;
    return newNode;
  }

 public:
  Node* root;
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
  void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
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
  void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  };
  void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  };
};

int displayMenu() {
  int choice;
  cout << "===============================================" << endl;
  cout << "1. Insert a value" << endl;
  cout << "2. Preorder Traversal" << endl;
  cout << "3. Inorder Traversal" << endl;
  cout << "4. Postorder Traversal" << endl;
  cout << "5. Search" << endl;
  cout << "6. Exit" << endl;
  cout << "===============================================" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main() {
  BinaryTree tree;
  while (1) {
    switch (displayMenu()) {
      case 1:
        tree.insertValue();
        break;
      case 2:
        tree.preOrder(tree.root);
        break;
      case 3:
        tree.inorder(tree.root);
        break;
      case 4:
        tree.postorder(tree.root);
        break;
      case 5:
        int value;
        cout << "Enter the value to be searched: ";
        cin >> value;
        if (tree.search(value))
          cout << "Element found" << endl;
        else
          cout << "Element not found" << endl;
        break;
      case 6:
        return 0;
    }
  }
  return 0;
}