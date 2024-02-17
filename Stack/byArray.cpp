#include <iostream>

using namespace std;

class Stack {
  int checkFull() {
    if (size >= MAX_SIZE) return 1;
    return 0;
  }

 public:
  int *arr;
  int MAX_SIZE;
  int size;
  Stack(int maxSize) {
    arr = new int[maxSize];
    MAX_SIZE = maxSize;
    size = 0;
  }
  void push() {
    if (checkFull()) {
      cout << "Stack Overflow" << endl;
      return;
    } else {
      int data;
      cout << "Enter a number";
      cin >> data;
      arr[size] = data;
      size++;
    }
  }
  int pop() {
    if (size == 0) {
      cout << "Stack is already empty" << endl;
      return -1;
    }
    int deleteValue = arr[size - 1];
    arr[size - 1] = 0;
    size--;
    return deleteValue;
  }
  int peep() {
    if (size == 0) {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return arr[size - 1];
  }
  void display() {
    cout << "------------------------" << endl;
    for (int i = size - 1; i >= 0; i--) {
      cout << "| " << arr[i] << " |" << endl;
    }
    cout << "------------------------" << endl;
    cout << endl;
  }
};

int displayMenu() {
  int choice;
  cout << "===============================================" << endl;
  cout << "1. Push" << endl;
  cout << "2. Pop" << endl;
  cout << "3. Peep" << endl;
  cout << "4. Display" << endl;
  cout << "5. Exit" << endl;
  cout << "===============================================" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main() {
  int maxSize;
  cout << "Enter the size of the stack: ";
  cin >> maxSize;
  Stack stack(maxSize), stack2(maxSize);
  int choice;
  do {
    choice = displayMenu();
    switch (choice) {
      case 1:
        stack.push();
        break;
      case 2: {
        int val = stack.pop();
        if (val != -1) cout << "Popped " << val << endl;
        break;
      }
      case 3:
        cout << "Peeped " << stack.peep() << endl;
        break;
      case 4:
        stack.display();
        break;
      case 5:
        cout << "Exiting...";
        break;
      default:
        cout << "Invalid choice";
    }
  } while (choice != 5);
  return 0;
}
