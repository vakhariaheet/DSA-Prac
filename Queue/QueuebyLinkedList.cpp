#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node() { next = NULL; }
};
class Queue {
  Node* rear;
  Node* front;
  Node* createNode() {
    Node* newNode = new Node();
    cout << "Enter a number";
    cin >> newNode->data;
    return newNode;
  }

 public:
  int size;
  Queue() {
    size = 0;
    rear = front = NULL;
  }
  void enqueue() {
    if (front == NULL && rear == NULL) {
      size++;
      front = rear = createNode();
      return;
    }
    rear->next = createNode();
    rear = rear->next;
    size++;
  };
  int dequeue() {
    if (front == NULL) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    int val = front->data;
    Node* ptr = front;
    front = front->next;
    delete ptr;
    size--;
    return val;
  }
  int peek() {
    if (front == NULL) {
      cout << "Queue is empty" << endl;
      return 0;
    }
    return front->data;
  }

  void display() {
    Node* currentNode = front;
    while (currentNode != NULL) {
      cout << currentNode->data << "\t";
      currentNode = currentNode->next;
    }
    cout << endl;
  }
};

int displayMenu() {
  int choice;
  cout << "===============================================" << endl;
  cout << "1. Enqueue" << endl;
  cout << "2. Dequeue" << endl;
  cout << "3. Display" << endl;
  cout << "4. Peek" << endl;
  cout << "5. Exit" << endl;
  cout << "===============================================" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main() {
  Queue q;
  while (1) {
    switch (displayMenu()) {
      case 1:
        q.enqueue();
        break;
      case 2:
        if (q.size == 0) {
          cout << "Queue is empty" << endl;
          break;
        }
        cout << "Dequeued: " << q.dequeue() << endl;
        break;
      case 3:
        q.display();
        break;
      case 4:
        if(q.size == 0) {
          cout << "Queue is empty" << endl;
          break;
        }
        cout << "Peek: " << q.peek() << endl;
        break;
      case 5:
        exit(0);
        break;
      default:
        cout << "Invalid choice" << endl;
    }
  }
  return 0;
}
