#include <iostream>

using namespace std;

class Stack {
 public:
  int MAX_SIZE;
  int *arr;
  int size;
  Stack(int maxSize) {
    arr = new int[maxSize];
    MAX_SIZE = maxSize;
    size = 0;
  }
  void push() {
    if (size >= MAX_SIZE) {
      cout << "Stack Overflow" << endl;
      return;
    }
    int data;
    cout << "Enter a number";
    cin >> data;
    arr[size] = data;
    size++;
  }
  int pop() {
    if (size == 0) {
      cout << "Stack is already empty" << endl;
      return -1;
    }
    int val = arr[size - 1];
    arr[size - 1] = 0;
    size--;
    return val;
  }
  int peek() {
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
  Stack stack(maxSize);
  int choice;
  do {
    choice = displayMenu();
    switch (choice) {
      case 1:
        stack.push();
        break;
      case 2: {
        if(stack.size == 0) {
          cout << "Stack is already empty" << endl;
          break;
        }
        cout << "Popped " << stack.pop() << endl;
        break;
      }
      case 3:
        cout << "Peeped " << stack.peek() << endl;
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
