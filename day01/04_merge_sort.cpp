#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1e6;
int q[N], temp[N];

void merge_sort(int q[], int l, int r, long &res) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  merge_sort(q, l, mid, res);
  merge_sort(q, mid + 1, r, res);
  int i = l, j = mid + 1;
  int idx = 0;
  while (i <= mid && j <= r) {
    if (q[i] <= q[j]) {
      temp[idx++] = q[i++];
    } else {
      res += mid - i + 1;
      temp[idx++] = q[j++];
    }
  }
  while (i <= mid) temp[idx++] = q[i++];
  while (j <= r) temp[idx++] = q[j++];
  for (int k = l, index = 0; k <= r; k++) {
    q[k] = temp[index++];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &q[i]);
  long res = 0;
  merge_sort(q, 0, n - 1, res);
  printf("%ld ", res);
}