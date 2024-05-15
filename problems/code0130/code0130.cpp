#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<char>>& board, int x, int y, int n, int m) {
  if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
    return;
  }

  board[x][y] = 'A';

  dfs(board, x - 1, y, n, m);
  dfs(board, x + 1, y, n, m);
  dfs(board, x, y - 1, n, m);
  dfs(board, x, y + 1, n, m);
}

void solve(std::vector<std::vector<char>>& board) {
  int n = board.size();

  if (n == 0) {
    return;
  }

  int m = board[0].size();

  // rows
  for (int i = 0; i < n; i++) {
    // first cols
    dfs(board, i, 0, n, m);
    // last cols
    dfs(board, i, m - 1, n, m);
  }

  // cols
  for (int j = 0; j < m; j++) {
    // first row
    dfs(board, 0, j, n, m);
    // last row
    dfs(board, n - 1, j, n, m);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'A') {
        board[i][j] = 'O';
      } else if (board[i][j] == 'O') {
        board[i][j] = 'X';
      }
    }
  }
}

int main() { return 0; }