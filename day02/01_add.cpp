#include <bits/stdc++.h>
using namespace std;

string num1, num2;
vector<int> add(vector<int> A, vector<int> B) {
  if (A.size() < B.size()) {
    return add(B, A);
  }
  int t = 0;
  vector<int> ans;
  int i = 0, j = 0;
  while (i < A.size() && j < B.size()) {
    t += A[i++] + B[j++];
    ans.push_back(t % 10);
    t /= 10;
  }
  if (i < A.size()) {
    t += A[i++];
    ans.push_back(t % 10);
    t /= 10;
  }
  while (t) {
    ans.push_back(t % 10);
    t /= 10;
  }
  return ans;
}

int main() {
  cin >> num1 >> num2;
  vector<int> A, B;
  for (int i = num1.size() - 1; i >= 0; i--) {
    A.push_back(num1[i] - '0');
  }
  for (int i = num2.size() - 1; i >= 0; i--) {
    B.push_back(num2[i] - '0');
  }
  vector<int> ans = add(A, B);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[ans.size() - i - 1];
  }
  cout << endl;
  return 0;
}