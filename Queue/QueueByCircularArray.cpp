#include <iostream>

using namespace std;

class Queue {
  int MAX_SIZE, front, rear;
  int *arr;
  int checkFull() {
    int nextRear = (rear + 1) % MAX_SIZE;
    if (nextRear == front) return 1;
    return 0;
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
    if (front == -1) {
      front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    cout << "Enter a number:";
    cin >> arr[rear];
  }
  void dequeue() {
    if (rear == -1 && front == -1) {
      cout << "Queue is Empty" << endl;
      return;
    }
    if (front == rear) {
      front = rear = -1;
      return;
    }
    cout << endl << "Front: " << front << " Rear " << rear << endl;
    front = (front + 1) % MAX_SIZE;
    arr[front] = 0;
  }

  void display() {
    cout << front << ":" << rear << " " << (rear + 1) % MAX_SIZE << endl;
    int i;

    for (i = front; rear != i; i = (i + 1) % MAX_SIZE) {
      cout << arr[i] << "\t";
    }
    cout << arr[i] << endl;
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
        break;
      case 4:
        queue.display();
        break;
      case 5:
        exit(0);
    }
  }
  return 0;
}