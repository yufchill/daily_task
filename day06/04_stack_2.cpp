#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int st[N];
int top = -1;
int n;

int main() {
  cin >> n;
  int num;
  while (n--) {
    cin >> num;
    while (top != -1 && st[top] >= num) {
      top--;
    }
    if (top == -1) {
      cout << -1 << " ";
    } else {
      cout << st[top] << " ";
    }
    st[++top] = num;
  }
  return 0;
}