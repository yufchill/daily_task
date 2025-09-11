#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int m;
int cur = 1;
int e[N];   // 第K个插入的值为 e[k]
int ne[N];  // 第k个插入的next的下标为ne[k]

void Add(int k, int x) {
  e[cur] = x;
  ne[cur] = ne[k];
  ne[k] = cur++;
}
void Delete(int k) {
  ne[k] = ne[ne[k]];
  return;
}
int main() {
  cin >> m;
  ne[0] = -1;
  while (m--) {
    char op;
    cin >> op;
    if (op == 'H') {
      int x;
      cin >> x;
      Add(0, x);
    } else if (op == 'D') {
      int k;
      cin >> k;
      Delete(k);
    } else if (op == 'I') {
      int k, x;
      cin >> k >> x;
      Add(k, x);
    }
  }
  int start = 0;
  while (1) {
    int start = ne[start];
    if (start == -1) {
      return 0;
    }
    cout << e[start] << " ";
  }
}