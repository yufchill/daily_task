#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e6;
int q[N];

int binary_search(int q[], int l, int r, int target) {
  while (l <= r) {
    int mid = (l + r) / 2;
    if (q[mid] < target) {
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return l;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }
  while (m--) {
    int num;
    cin >> num;
    int res1 = binary_search(q, 0, n - 1, num);
    int res2 = binary_search(q, 0, n - 1, num + 1);
    if (res1 >= n || q[res1] != num) {
      cout << "-1 -1" << endl;
    } else {
      cout << res1 << " " << res2 - 1 << endl;
    }
  }
}