#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  vector<pair<int, int>> intervals;
  cin >> n;
  while (n--) {
    int l, r;
    cin >> l >> r;
    intervals.push_back({l, r});
  }
  sort(intervals.begin(), intervals.end());
  int cur = intervals[0].second;
  int res = 1;
  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i].first > cur) {
      res++;
      cur = intervals[i].second;
    } else {
      cur = max(cur, intervals[i].second);
    }
  }
  cout << res << endl;
}