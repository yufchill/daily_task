#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int st[N];
int top = -1;
int m;

void push(int x) {
  st[++top] = x;
  return;
}

void pop() {
  int res = st[top];
  top--;
}

bool empty() { return top == -1; }

int query() { return st[top]; }

int main() {
  cin >> m;
  while (m--) {
    string op;
    int x;
    cin >> op;
    if (op == "push") {
      cin >> x;
      push(x);
    } else if (op == "pop") {
      pop();
    } else if (op == "query") {
      cout << query() << endl;
    } else if (op == "empty") {
      cout << (empty() ? "YES" : "NO") << endl;
    }
  }
  return 0;
}