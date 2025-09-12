#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int M;
int q[N];
int head = 0;
int tail = 0;

void push(int x) { q[tail++] = x; }

void pop() { head++; }

bool empty() { return head == tail; }

int query() { return q[head]; }

int main() {
  cin >> M;
  while (M--) {
    string op;
    int x;
    cin >> op;
    if (op == "push") {
      cin >> x;
      push(x);
    } else if (op == "pop") {
      pop();
    } else if (op == "empty") {
      cout << (empty() ? "YES" : "NO") << endl;
    } else if (op == "query") {
      cout << query() << endl;
    }
  }
}
