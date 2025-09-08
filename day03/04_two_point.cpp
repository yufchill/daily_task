#include <bits/stdc++.h>
using namespace std;

int n, m, x;

int main() {
  cin >> n >> m >> x;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int i = 0, j = m - 1;
  while (1) {
    int sum = a[i] + b[j];
    if (sum == x) {
      cout << i << " " << j << endl;
      return 0;
    } else if (sum < x) {
      i++;
    } else {
      j--;
    }
  }
  return 0;
}