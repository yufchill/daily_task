#include <bits/stdc++.h>
using namespace std;

string a;
int B;
vector<int> muti(vector<int> A, int B) {
  vector<int> ans;
  int t = 0;
  for (int i = 0; i < A.size(); i++) {
    t = A[i] * B + t;
    ans.push_back(t % 10);
    t = t / 10;
  }
  if (t) {
    ans.push_back(t);
  }
  return ans;
}
int main() {
  cin >> a >> B;
  if (B == 0) {
    cout << "0" << endl;
    return 0;
  }
  vector<int> A;
  for (int i = a.size() - 1; i >= 0; i--) {
    A.push_back(a[i] - '0');
  }
  vector<int> ans = muti(A, B);
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i];
  }
  cout << endl;
}