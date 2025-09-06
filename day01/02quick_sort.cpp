#include <bits/stdc++.h>
using namespace std;

int n;
int q[100000];

void quick_sort(int q[], int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  int x = q[mid];
  int i = l - 1;
  int j = r + 1;
  while (i < j) {
    while (q[++i] < x);
    while (q[--j] > x);
    if (i < j) {
      swap(q[i], q[j]);
    }
  }
  quick_sort(q, l, j);
  quick_sort(q, j + 1, r);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }
  quick_sort(q, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << q[i] << " ";
  }
}