#include "stack.h"

// O(n+r)
int main() {
  using std::cout;
  using std::cin;
  using std::endl;

  int n;  // number of elements
  int r;  // number of relationships

  cout << "Enter number of elements." << endl;
  cin >> n;
  if (n < 2) {
    cout << "Too few elemnts." << endl;
    return 1;
  }
  cout << "Enter number of relations." << endl;
  cin >> r;
  if (r < 1) {
    cout << "Too few relations" << endl;
  }

  ArrayStack<int>* list = new ArrayStack<int>[n + 1];

  // input r relationships
  int a, b;  // relation (a, b)
  for (int i = 1; i <= r; ++i) {
    cout << "Enter next relationship/pair" << endl;
    cin >> a >> b;
    list[a].push(b);
    list[b].push(a);
  }

  ArrayStack<int> unprocessedList;
  bool* out = new bool[n + 1];
  for (int i = 1; i <= n; ++i) {
    out[i] = false;
  }
  for (int i = 1; i <= n; ++i) {
    if (!out[i]) {
      cout << "Next class is: " << i << " ";
      out[i] = true;
      unprocessedList.push(i);

      while (!unprocessedList.empty()) {
        int j = unprocessedList.top();
        unprocessedList.pop();
        while (!list[j].empty()) {
          int q = list[j].top();
          list[j].pop();
          if (!out[q]) {
            cout << q << " ";
            out[q] = true;
            unprocessedList.push(q);
          }
        }
      }
    }
    cout << endl;
  }
  cout << "End of list of equivalence classes." << endl;
  return 0;
}
