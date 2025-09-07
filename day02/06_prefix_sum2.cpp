#include <bits/stdc++.h>
using namespace std;
int n, m, q;

int main() {
  cin >> n >> m >> q;
  vector<vector<int>> matrix(n + 1, vector<int>(m + 1));
  int num;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> num;
      matrix[i + 1][j + 1] =
          matrix[i + 1][j] + matrix[i][j + 1] - matrix[i][j] + num;
    }
  }
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << matrix[x2][y2] - matrix[x2][y1 - 1] - matrix[x1 - 1][y2] +
                matrix[x1 - 1][y1 - 1]
         << endl;
  }
}