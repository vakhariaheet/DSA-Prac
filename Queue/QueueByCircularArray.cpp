#include <iostream>

using namespace std;

class Queue {
  int MAX_SIZE, front, rear;
  int *arr;
  int checkFull() {
    if (rear > MAX_SIZE && front == 0) {
      cout << "dfaffdsfdd";
      return 1;
    } else if (rear == MAX_SIZE && front > 1) {
      rear = 0;
      return 0;
    }
    if (rear > front && rear <= MAX_SIZE) return 1;
  }

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
    if (front == 0 && rear + 1 == front) {
      cout << "Queue Underflow" << endl;
      return;
    }
    if (front == MAX_SIZE - 1) {
      front = 0;
    }
    arr[front] = 0;
    front++;
  }

  void display() {
    if (rear > front) {
      for (int i = front; i < rear; i++) {
        cout << arr[i] << "\t";
      }
    }

    if (front != 0 && rear < front) {
      for (int i = front; i < MAX_SIZE; i++) {
        cout << arr[i] << "\t";
      }
      for (int i = 0; i < rear; i++) {
        cout << arr[i] << "\t";
      }
    }
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
        queue.display();
        break;
    }
  }
  return 0;
}