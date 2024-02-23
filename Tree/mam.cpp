#include <iostream>
using namespace std;
class node {
 public:
  int data;
  node *left;
  node *right;
};
node *tree = NULL;
node *insert(node *tree, int val) {
  node *ptr, *nodeptr, *parentptr;
  ptr = new node();
  ptr->data = val;
  ptr->left = NULL;
  ptr->right = NULL;
  if (tree == NULL) {
    tree = ptr;
    tree->left = NULL;
    tree->right = NULL;
  } else {
    parentptr = NULL;
    nodeptr = tree;
    while (nodeptr != NULL) {
      parentptr = nodeptr;
      if (val < nodeptr->data)
        nodeptr = nodeptr->left;
      else
        nodeptr = nodeptr->right;
    }
    if (val < parentptr->data)
      parentptr->left = ptr;
    else
      parentptr->right = ptr;
  }
  return tree;
}
void printTree(node *root, int space = 0, int indent = 4) {
  if (root == nullptr) return;

  space += indent;

  printTree(root->right, space);

  std::cout << std::endl;
  for (int i = indent; i < space; i++) std::cout << " ";
  std::cout << root->data << "\n";

  printTree(root->left, space);
}
void preorder(node *tree) {
  if (tree != NULL) {
    cout << tree->data << endl;
    preorder(tree->left);
    preorder(tree->right);
  }
}
void postorder(node *tree) {
  if (tree != NULL) {
    postorder(tree->left);
    postorder(tree->right);
    cout << tree->data << endl;
  }
}
int search_element(node *tree, int item, int flag) {
  if (tree == NULL) {
    return flag;
  }
  while (tree != NULL) {
    if (tree->data == item) {
      flag = 1;
      return flag;
    } else {
      if (item < tree->data) {
        tree = tree->left;
      } else {
        tree = tree->right;
      }
    }
  }
  return flag;
}
int main() {
  int option, val, flag, item;
  node *ptr;
  do {
    flag = 0;
    cout << "\n************* MAIN MENU ****************\n";
    cout << "\n1. Insert";
    cout << "\n2.In order";
    cout << "\n3.Pre order";
    cout << "\n4.Post order";
    cout << "\n5.Search element";
    cout << "\n6. Exit";
    cout << "\n\n***************************************";
    cout << "\n\nEnter your option:";
    cin >> option;
    switch (option) {
      case 1:
        cout << "Enter value" << endl;
        cin >> val;
        tree = insert(tree, val);
        break;
      case 2:
        cout << "\n the elements of the tree are:\n";
        printTree(tree);
        break;
      case 3:
        cout << "\n the elements of the tree are:\n";
        preorder(tree);
        break;
      case 4:
        cout << "\n the elements of the tree are:\n";
        postorder(tree);
        break;
      case 5:
        cout << "\nEnter the element you want to search: ";
        cin >> item;
        flag = search_element(tree, item, flag);
        if (flag == 0) {
          cout << "\n\nElement is not present in the tree !";
        } else {
          cout << "\n\nElement is present in the tree !";
        }
        break;
    }
  } while (option != 6);
  return 0;
}