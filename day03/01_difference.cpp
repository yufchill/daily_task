#include <bits/stdc++.h>
using namespace std;

int n, m;

void insert(int l, int r, int c, vector<int>& a) {
  a[l] += c;
  a[r + 1] -= c;
}

int main() {
  cin >> n >> m;
  vector<int> a(n + 1);
  int cur;
  for (int i = 1; i <= n; i++) {
    cin >> cur;
    insert(i, i, cur, a);
  }
  while (m--) {
    int l, r, c;
    cin >> l >> r >> c;
    insert(l, r, c, a);
  }
  cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += a[i];
    cout << cur << " ";
  }
}