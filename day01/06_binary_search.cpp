#include <bits/stdc++.h>
using namespace std;

double n;

int main() {
  cin >> n;
  double l = -1e6;
  double r = 1e6;
  while (r - l > 1e-8) {
    double mid = (r + l) / 2;
    if (mid * mid * mid < n) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%.6f", l);
}