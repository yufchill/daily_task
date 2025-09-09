#include <bits/stdc++.h>
using namespace std;

int n, m;

int find(int target, const vector<int>& used) {
  int l = 0, r = used.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (used[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int main() {
  cin >> n >> m;
  vector<pair<int, int>> add, query;
  vector<int> used;
  while (n--) {
    int x, c;
    cin >> x >> c;
    add.push_back({x, c});
    used.push_back(x);
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    query.push_back({l, r});
    used.push_back(l);
    used.push_back(r);
  }
  sort(used.begin(), used.end());
  used.erase(unique(used.begin(), used.end()), used.end());

  vector<int> a(used.size());
  for (auto& p : add) {
    int idx = find(p.first, used);
    a[idx] += p.second;
  }
  vector<int> prefix(used.size() + 1, 0);
  for (int i = 1; i <= used.size(); i++) {
    prefix[i] = prefix[i - 1] + a[i - 1];
  }
  for (auto& p : query) {
    int l = find(p.first, used);
    int r = find(p.second, used);
    cout << prefix[r + 1] - prefix[l] << endl;
  }
}