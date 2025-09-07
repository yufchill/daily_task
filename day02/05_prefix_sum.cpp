#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  vector<int> nums(n);
  vector<int> prefix(n + 1, 0);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    cur += nums[i];
    prefix[i + 1] = cur;
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << prefix[r] - prefix[l - 1] << endl;
  }
}