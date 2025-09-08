#include <bits/stdc++.h>
using namespace std;

int n, m, q;
void insert(int x1, int y1, int x2, int y2, int c,
            vector<vector<int>> &matrix) {
  matrix[x1][y1] += c;
  matrix[x2 + 1][y2 + 1] += c;
  matrix[x2 + 1][y1] -= c;
  matrix[x1][y2 + 1] -= c;
}

int main() {
  cin >> n >> m >> q;
  // cout << q << endl;
  vector<vector<int>> matrix(n + 10, vector<int>(m + 10, 0));
  int num;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> num;
      insert(i, j, i, j, num, matrix);
    }
  }
  while (q--) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    insert(x1, y1, x2, y2, c, matrix);
  }
  vector<vector<int>> res(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      res[i][j] =
          res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1] + matrix[i][j];
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}