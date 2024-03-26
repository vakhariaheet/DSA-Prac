#include <bits/stdc++.h>
using namespace std;

int main() {
  // It maintains a singly Linked List
  vector<int> ve;

  // Will add element at end
  ve.push_back(3);

  // will also element at end but is faster compare to push_back
  ve.emplace_back(2);

  vector<pair<int, int>> vec;

  vec.push_back({1, 2});

  // will insert a pair
  vec.emplace_back(1, 2);

  // will set initially size of 5 and set 100 to all 5 position
  vector<int> vecInt(5, 100);

  // will set initially size of 5 and set to garbage values to all positions
  vector<int> vc(5);

  // will copy contents of vecInt and create new vector v2;
  vector<int> v2(vecInt);

  // Accessing vector element using index
  cout << ve[0] << " " << ve.at(0) << endl;

  // Accessing vector element using iterators
  //-- Will create iterator it, which will store addr of first element
  vector<int>::iterator it = vecInt.begin();
  cout << *(it) << " ";

  //-- Will increment iterator.
  it++;
  cout << *(it) << " " << endl;

  //-- Iterator will jump by 2 place
  it = it + 2;

  //-- Will create iterator end, will store addr of last Element + 1 (i.e Addr
  //-- where new element will be stored)
  vector<int>::iterator end = vecInt.end();

  //-- For Reverse Order
  vector<int>::reverse_iterator revB = vecInt.rbegin();
  vector<int>::reverse_iterator revE = vecInt.rend();

  //-- Using loops
  //-- auto will automatically set the datatype of variable
  for (auto it = vecInt.begin(); it != vecInt.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;

  for (auto it : vecInt) {
    cout << it << " ";
  }

  // Will Return the size of the vector
  vecInt.size();

  // Will Delete and return the first element of the vector
  vecInt.pop_back();

  // Will remove first element
  vecInt.erase(vecInt.begin());

  // Will remove 2nd and 3rd element
  vecInt.erase(vecInt.begin() + 1, vecInt.begin() + 3);

  // Will tell if the vector is empty
  vecInt.empty();

  // Will remove all Elements from the vector
  vecInt.clear();

  // Will Swap all elements of the given vector
  vecInt.swap(ve);
}