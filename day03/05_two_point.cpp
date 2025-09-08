#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] == b[j++]) {
      i++;
    }
  }
  if (i != n) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}