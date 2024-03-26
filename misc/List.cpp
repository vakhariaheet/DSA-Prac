// List is similar to Vector
// Only Difference is it maintains a doubly Linked List

#include <bits/stdc++.h>

int main() {
  list<int> ls;

  // Will insert element at the last
  ls.push_back(4);

  // Will also insert element at the last
  ls.emplace_back(5);

  // Will insert element at the front
  ls.push_front(4);

  // Will also insert element at the front
  ls.emplace_front(56);
}