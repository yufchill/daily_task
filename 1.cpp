#include <bits/stdc++.h>
using namespace std;

int n;
int q[100000];

void quick_sort(int q[], int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  int x = q[mid];
  int i = l;
  int j = r;
  while (i < j) {
    while (q[i] < x) {
      i++;
    }
    while (q[j] > x) {
      j--;
    }
    if (i <= j) {
      swap(q[i], q[j]);
      i++;
      j--;
    }
  }
  quick_sort(q, l, j);
  quick_sort(q, i, r);
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