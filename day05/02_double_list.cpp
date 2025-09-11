#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int m;
int cur = 2;
int e[N];
int r[N];
int l[N];

// 在下标为k的数后面插入
void Add(int k, int x) {
  e[cur] = x;  // 插入

  l[cur] = k;
  l[r[k]] = cur;
  r[cur] = r[k];
  r[k] = cur++;
}
// 删除下标为k的数
void Delete(int k) {
  r[l[k]] = r[k];
  l[r[k]] = l[k];
}

int main() {
  cin >> m;
  r[0] = 1;
  l[1] = 0;

  while (m--) {
    string op;
    cin >> op;
    if (op == "L") {
      int x;
      cin >> x;
      Add(0, x);
    } else if (op == "R") {
      int x;
      cin >> x;
      Add(l[1], x);
    } else if (op == "D") {
      int k;
      cin >> k;
      Delete(k + 1);
    } else if (op == "IL") {
      int k, x;
      cin >> k >> x;
      Add(l[k + 1], x);
    } else if (op == "IR") {
      int k, x;
      cin >> k >> x;
      Add(k + 1, x);
    }
  }
  int start = 0;
  while (1) {
    start = r[start];
    if (start == 1) {
      return 0;
    }
    cout << e[start] << " ";
  }
}