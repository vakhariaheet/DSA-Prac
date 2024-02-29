#include <iostream>

using namespace std;

class Queue {
  // Rear is Last Element and front is First Element
  int MAX_SIZE, front, rear;
  int *arr;
  int checkFull() {
    int nextRear = (rear + 1) % MAX_SIZE;
    if (nextRear == front) return 1;
    return 0;
  }

 public:
  int size;
  Queue(int maxSize) {
    MAX_SIZE = maxSize;
    arr = new int[MAX_SIZE];
    rear = front = -1;
    size = 0;
  }
  void enqueue() {
    if (checkFull()) {
      cout << "Queue is Full" << endl;
      return;
    }
    size++;
    if (front == -1) {
      front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    cout << "Enter a number:";
    cin >> arr[rear];
  }
  int dequeue() {
    if (rear == -1 && front == -1) {
      cout << "Queue is Empty" << endl;
      return -1;
    }
    size--;
    if (front == rear) {
      int val = arr[front];
      front = rear = -1;
      return val;
    }
    int val = arr[front];
    arr[front] = 0;
    front = (front + 1) % MAX_SIZE;
    return val;
  }

  void display() {
    if (front == -1 && rear == -1) {
      cout << "Queue is empty" << endl;
      return;
    }
    int currentEle = front;
    do {
      cout << arr[currentEle] << "\t";
      currentEle = (currentEle + 1) % MAX_SIZE;
    } while (currentEle != (rear + 1) % MAX_SIZE);
    cout << endl;
  }

  int peek() {
    if (front == -1) {
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
        if (queue.size == 0) {
          cout << "Queue is empty" << endl;
          break;
        }
        cout << "Dequeued: " << queue.dequeue() << endl;
        break;
      case 3:
        if (queue.size == 0) {
          cout << "Queue is empty" << endl;
          break;
        }
        cout << "Peek: " << queue.peek() << endl;
        break;
      case 4:
        queue.display();
        break;
      case 5:
        return 0;
    }
  }
  return 0;
}