#include <bits/stdc++.h>
using namespace std;

int n;
int count(int num) {
  int res = 0;
  while (num) {
    res += num % 2;
    num >>= 1;
  }
  return res;
}

int lowbit(int x) { return x & -x; }
int count2(int num) {
  int res = 0;
  while (num) {
    num -= lowbit(num);
    res++;
  }
  return res;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    cout << count2(num) << " ";
  }
}