#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  unordered_map<int, int> mp;
  int l = 0, r = 0;
  int ans = 0;
  for (; r < n; r++) {
    mp[a[r]]++;
    while (mp[a[r]] > 1) {
      mp[a[l++]]--;
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans << endl;
}