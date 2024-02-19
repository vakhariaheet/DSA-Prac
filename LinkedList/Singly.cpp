#include <iostream>

using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node() { next = NULL; }
};

class LinkedList {
  Node* head;
  Node* createNode(int data = -1) {
    Node* newNode = new Node();
    if (data == -1) {
      cout << "Enter a number";
      cin >> newNode->data;
    } else {
      newNode->data = data;
    }
    return newNode;
  }

 public:
  LinkedList() { head = NULL; }
  void createList() {
    int data;
    Node* currentNode = head;
    if (head != NULL) {
      while (currentNode->next != NULL) currentNode = currentNode->next;
    }
    while (1) {
      cout << "Enter a number:";
      cin >> data;
      if (data == -1) break;
      if (head == NULL) {
        head = currentNode = createNode(data);
        continue;
      }
      currentNode->next = createNode(data);
      currentNode = currentNode->next;
    }
  }
  void insertAtBeginning() {
    if (head == NULL) {
      head = createNode();
      return;
    }
    Node* newNode = createNode();
    newNode->next = head;
    head = newNode;
  }
  void deleteAtBeginning() {
    if (head == NULL) {
      cout << "Linked list underflow";
      return;
    }
    Node* ptr = head;
    if (head == head->next) {
      head = NULL;
      delete ptr;
      return;
    }
    head = head->next;
    delete ptr;
  }

  void insertAtEnd() {
    if (head == NULL) {
      head = createNode();
      head->next = head;
      return;
    }

    Node* currentNode = head;
    while (currentNode->next != NULL) {
      currentNode = currentNode->next;
    }
    currentNode->next = createNode();
  }

  void deleteAtEnd() {
    if (head == NULL) {
      cout << "Linked list underflow";
      return;
    }
    Node* currentNode = head;
    while (currentNode->next->next != NULL) {
      currentNode = currentNode->next;
    }
    delete currentNode->next;
    currentNode->next = NULL;
  }

  void insertAfterValue() {
    if (head == NULL) {
      cout << "Linked List is empty" << endl;
      return;
    }
    int value;
    cout << "Enter a value after which you want to insert:";
    cin >> value;
    Node* currentNode = head;
    while (currentNode->data != value && currentNode->next != NULL) {
      currentNode = currentNode->next;
    }
    if (currentNode->data != value) {
      cout << "Node not found" << endl;
      return;
    }
    Node* newNode = createNode();
    newNode->next = currentNode->next;
    currentNode->next = newNode;
  }

  void deleteAfterValue() {
    if (head == NULL) {
      cout << "Linked List is empty" << endl;
      return;
    }
    int value;
    cout << "Enter a value after which you want to delete:";
    cin >> value;
    Node* currentNode = head;
    while (currentNode->data != value && currentNode->next != NULL) {
      currentNode = currentNode->next;
    }
    if (currentNode->data != value) {
      cout << "Node not found" << endl;
      return;
    }

    Node* ptr = currentNode->next;
    currentNode->next = currentNode->next->next;
    delete ptr;
  }

  void display() {
    Node* currentNode = head;
    do {
      cout << currentNode->data << "\t";
      currentNode = currentNode->next;
    } while (currentNode != NULL);
    cout << endl;
  }
};

int displayMenu() {
  int choice;
  cout << "===============================================" << endl;
  cout << "1. Create List" << endl;
  cout << "2. Insert at beginning" << endl;
  cout << "3. Delete at beginning" << endl;
  cout << "4. Insert at end" << endl;
  cout << "5. Delete at end" << endl;
  cout << "6. Insert after value" << endl;
  cout << "7. Delete after value" << endl;
  cout << "8. Display" << endl;
  cout << "9. Exit" << endl;
  cout << "===============================================" << endl;
  cout << "Enter your choice:";
  cin >> choice;
  return choice;
}
int main() {
  LinkedList list;
  int choice;
  do {
    choice = displayMenu();
    switch (choice) {
      case 1:
        list.createList();
        break;
      case 2:
        list.insertAtBeginning();
        break;
      case 3:
        list.deleteAtBeginning();
        break;
      case 4:
        list.insertAtEnd();
        break;
      case 5:
        list.deleteAtEnd();
        break;
      case 6:
        list.insertAfterValue();
        break;
      case 7:
        list.deleteAfterValue();
        break;
      case 8:
        list.display();
        break;
    }
  } while (choice != 9);
  return 0;
}