#include <iostream>
// NOTE : This is a simple implementation of a queue using an array.
// Not the most efficient one
// For a more efficient implementation, refer to QueueByLinkedList.cpp or
// QueueByCircularArray.cpp
// This implementation one big disadvantage, that is, it does not use the
// memory efficiently. When the queue is full, it does not reuse the empty
// spaces in the array. This is because the front pointer is not reset to 0
using namespace std;

class Queue {
  int MAX_SIZE, front, rear;
  int *arr;
  int checkFull() { return rear >= MAX_SIZE; }

 public:
  Queue(int maxSize) {
    MAX_SIZE = maxSize;
    arr = new int[MAX_SIZE];
    rear = front = -1;
  }
  void enqueue() {
    if (checkFull()) {
      cout << "Queue is Full" << endl;
      return;
    }
    if (front == -1 && rear == -1) {
      front = rear = 0;
    }
    cout << "Enter a number:";
    cin >> arr[rear];
    rear++;
  }
  void dequeue() {
    if (front == -1 || front > rear) {
      cout << "Queue Underflow" << endl;
      return;
    }
    if (front) arr[front] = 0;
    front++;
  }
  void display() {
    for (int i = front; i < rear; i++) {
      cout << arr[i] << "\t";
    }
    cout << endl;
  }
  int peek() {
    if (front == -1 || front > rear) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    return arr[front];
  }
};

int displayMenu() {
  int choice;
  cout << "===============================================" << endl;
  cout << "1. Enqueue" << endl;
  cout << "2. Dequeue" << endl;
  cout << "3. Peek" << endl;
  cout << "4. Display" << endl;
  cout << "5. Exit" << endl;
  cout << "===============================================" << endl;
  cout << "Enter your choice:";

  cin >> choice;
  return choice;
}

int main() {
  int maxSize;
  cout << "Enter the maximum size of the queue:";
  cin >> maxSize;
  Queue queue(maxSize);
  while (1) {
    switch (displayMenu()) {
      case 1:
        queue.enqueue();
        break;
      case 2:
        queue.dequeue();
        break;
      case 3:
        cout << "Peek: " << queue.peek() << endl;
        break;
      case 4:
        queue.display();
        break;
      case 5:
        cout << "Exiting..." << endl;
        return 0;
    }
  }
  return 0;
}