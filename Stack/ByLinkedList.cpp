#include <iostream>
using namespace std;
class Node {
 public:
  int data;
  Node* next;
  Node() {
    data = 0;
    next = NULL;
  }
};
class Stack {
  Node* top;
  int checkFull() {
    if (MAX_SIZE == -1) return 0;
    if (size >= MAX_SIZE) return 1;
    return 0;
  };
  Node* createNode(int data = -1) {
    Node* newNode = new Node();
    if (data == -1) {
      cout << "Enter a number";
      cin >> newNode->data;
    } else {
      newNode->data = data;
    }
    size++;
    return newNode;
  }

 public:
  int MAX_SIZE;
  int size;
  Stack(int maxElements = -1) {
    MAX_SIZE = maxElements;
    size = 0;
    top = NULL;
  }
  void push() {
    if (checkFull()) {
      cout << "Stack Overflow";
      return;
    }
    Node* newNode = createNode();
    newNode->next = top;
    top = newNode;
  }
  int pop() {
    if (top == NULL) {
      cout << "Stack is empty";
      return -1;
    }
    Node* oldTop = top;
    top = top->next;
    int value = oldTop->data;
    delete oldTop;
    size--;
    return value;
  }
  int peep() {
    if (top == NULL) {
      cout << "Stack is empty";
      return -1;
    };
    return top->data;
  }
  void display() {
    if (top == NULL) {
      cout << "Stack is empty";
      return;
    }
    Node* currentNode = top;
    cout << "------------------------" << endl;
    while (currentNode != NULL) {
      cout << "| " << currentNode->data << " |" << endl;
      currentNode = currentNode->next;
    }
    cout << "------------------------" << endl;
    cout << endl;
  }
};

int displayMenu() {
  int choice;
  cout << "===============================" << endl;
  cout << "1. Push" << endl;
  cout << "2. Pop" << endl;
  cout << "3. Peep" << endl;
  cout << "4. Display" << endl;
  cout << "5. Exit" << endl;
  cout << "===============================" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main() {
  int maxElements;
  cout << "Enter the maximum number of elements in the stack (Enter -1 for "
          "infinite size): ";
  cin >> maxElements;
  Stack stack(maxElements);
  int choice;

  do {
    choice = displayMenu();
    switch (choice) {
      case 1: {
        stack.push();
        break;
      }
      case 2: {
        stack.pop();
        break;
      }
      case 3: {
        int val = stack.peep();
        if (val != -1) {
          cout << "The top element is: " << val << endl;
        }
        break;
      }
      case 4: {
        stack.display();
        break;
      }
      case 5: {
        return 0;
      }
      default:
        cout << "Invalid choice";
    }
  } while (1);
  return 0;
}