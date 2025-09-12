#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N], q[N];
int n, k;
int l = 0;
int r = -1;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    while (l <= r && a[q[r]] < a[i]) {
      r--;
    }
    q[++r] = i;
    if (i - q[l] >= k) {
      l++;
    }
    if (i + 1 >= k) {
      cout << a[q[l]] << " ";
    }
  }
}