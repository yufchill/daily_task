#include <bits/stdc++.h>
using namespace std;

string num1, num2;

bool cmp(vector<int> A, vector<int> B) {
  if (A.size() != B.size()) {
    return A.size() > B.size();
  }
  for (int i = A.size() - 1; i >= 0; i--) {
    if (A[i] > B[i]) {
      return true;
    } else if (A[i] < B[i]) {
      return false;
    } else {
      continue;
    }
  }
  return true;
}

vector<int> sub(vector<int> A, vector<int> B) {
  int i = 0, j = 0;
  int t = 0;
  vector<int> ans;
  while (i < A.size() && j < B.size()) {
    t = A[i++] - B[j++] - t;
    ans.push_back((t + 10) % 10);
    t = t >= 0 ? 0 : 1;
  }
  while (i < A.size()) {
    t = A[i++] - t;
    ans.push_back((t + 10) % 10);
    t = t >= 0 ? 0 : 1;
  }
  while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
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
  bool flag = cmp(A, B);
  if (flag) {
    vector<int> ans = sub(A, B);
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[ans.size() - i - 1];
    }
    cout << endl;
  } else {
    vector<int> ans = sub(B, A);
    cout << '-';
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[ans.size() - i - 1];
    }
    cout << endl;
  }

  return 0;
}