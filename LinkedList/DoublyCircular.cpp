#include <iostream>

using namespace std;

class Node {
 public:
  int data;
  Node* prev;
  Node* next;
  Node() { prev = next = NULL; }
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
      while (currentNode->next != head) currentNode = currentNode->next;
    }
    while (1) {
      cout << "Enter a number:";
      cin >> data;
      if (data == -1) break;
      if (head == NULL) {
        head = currentNode = createNode(data);
        head->prev = head;
        head->next = head;
        continue;
      }
      currentNode->next = createNode(data);
      currentNode->next->prev = currentNode;
      currentNode = currentNode->next;
    }
    head->prev = currentNode;
    currentNode->next = head;
  }
  void insertAtBeginning() {
    if (head == NULL) {
      head = createNode();
      head->next = head;
      head->prev = head;
      return;
    }
    Node* newNode = createNode();
    newNode->prev = head->prev;
    newNode->next = head;
    head->prev->next = newNode;
    head->prev = newNode;
    head = newNode;
  }
  void deleteAtBeginning() {
    if (head == NULL) {
      cout << "Linked list underflow";
      return;
    }
    Node* ptr = head;
    if (head->next == head) {
      delete ptr;
      head = NULL;
      return;
    }
    head->prev->next = head->next;
    head = head->next;
    head->prev = ptr->prev;
    delete ptr;
  }
  void insertAtLast() {
    if (head == NULL) {
      head = createNode();
      head->next = head;
      head->prev = head;
      return;
    }
    Node* currentNode = head;
    while (currentNode->next != head) {
      currentNode = currentNode->next;
    }
    currentNode->next = createNode();
    currentNode->next->prev = currentNode;
    currentNode->next->next = head;
    head->prev = currentNode->next;
    return;
  }
  void deleteAtLast() {
    if (head == NULL) {
      cout << "Linked list is empty" << endl;
      return;
    }

    Node* currentNode = head;
    if (head->next == head) {
      head = NULL;
      delete currentNode;
      return;
    }
    while (currentNode->next != head) {
      currentNode = currentNode->next;
    }
    Node* ptr = currentNode;
    currentNode = currentNode->prev;
    currentNode->next = head;
    head->prev = currentNode;
    delete ptr;
    return;
  }
  void insertAfterValue() {
    if (head == NULL) {
      cout << "Linked List is empty" << endl;
      return;
    }
    int value;
    cout << "Enter a value of the previous node after which you want to add a "
            "node";
    cin >> value;
    Node* currentNode = head;

    while (currentNode->data != value && currentNode->next != head) {
      currentNode = currentNode->next;
    }
    if (currentNode->data != value) {
      cout << "Node not found" << endl;
      return;
    }
    Node* newNode = createNode();
    newNode->next = currentNode->next;
    newNode->prev = currentNode;
    currentNode->next = newNode;
    newNode->next->prev = newNode;
  }
  void deleteAfterValue() {
    if (head == NULL) {
      cout << "Linked List is empty" << endl;
      return;
    }
    int value;
    cout << "Enter a value of the previous node after which you want to delete "
            "a node: ";
    cin >> value;
    Node* currentNode = head;

    while (currentNode->data != value && currentNode->next != head) {
      currentNode = currentNode->next;
    }
    if (currentNode->data != value || currentNode->next == head) {
      cout << "Node not found" << endl;
      return;
    }
    Node* ptr = currentNode->next;
    currentNode->next = ptr->next;
    ptr->next->prev = currentNode;
    delete ptr;
  }

  void display() {
    if (head == NULL) {
      cout << "List is empty" << endl;
      return;
    }
    Node* currentNode = head->next;
    cout << head->data << "\t";
    if (head->next == head) {
      cout << endl;
      return;
    }
    while (currentNode != head) {
      cout << currentNode->data << "\t";
      currentNode = currentNode->next;
    }
    cout << endl;
  }
  void reverse() {
    if (head == NULL) {
      cout << "List is empty" << endl;
      return;
    }
    Node* currentNode = head->prev;
    while (currentNode != head) {
      cout << currentNode->data << "\t";
      currentNode = currentNode->prev;
    }
    cout << currentNode->data << "\t";
    cout << endl;
  }
};

int displayMenu() {
  int choice;
  cout << "===============================================" << endl;
  cout << "1. Create List" << endl;
  cout << "2. Insert at Beginning" << endl;
  cout << "3. Delete at Beginning" << endl;
  cout << "4. Insert at Last" << endl;
  cout << "5. Delete at Last" << endl;
  cout << "6. Insert after value" << endl;
  cout << "7. Delete after value" << endl;
  cout << "8. Display" << endl;
  cout << "9. Reverse" << endl;
  cout << "10. Exit" << endl;
  cout << "===============================================" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

int main() {
  LinkedList list;
  while (1) {
    switch (displayMenu()) {
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
        list.insertAtLast();
        break;
      case 5:
        list.deleteAtLast();
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
      case 9:
        list.reverse();
        break;
      case 10:
        return 0;
      default:
        cout << "Invalid choice" << endl;
    }
  }
  return 0;
}