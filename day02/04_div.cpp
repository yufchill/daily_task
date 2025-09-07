#include <bits/stdc++.h>
using namespace std;

string a, b;
vector<int> div(vector<int> A, int B, int &t) {
  vector<int> ans;
  for (int i = 0; i < A.size(); i++) {
    t = t * 10 + A[i];
    ans.push_back(t / B);
    t = t % B;
  }
  reverse(ans.begin(), ans.end());
  while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
  return ans;
}

int main() {
  cin >> a >> b;
  vector<int> A;
  for (int i = 0; i < a.size(); i++) {
    A.push_back(a[i] - '0');
  }
  int B = stoi(b);
  int t = 0;
  vector<int> ans = div(A, B, t);
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i];
  }
  cout << endl << t << endl;
}