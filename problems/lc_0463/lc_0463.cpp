#include "headers.h"

using std::vector;

class Solution {
 public:
  int direction[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

  int islandPerimeter(vector<vector<int>>& grid) {
    int result = 0;
    for (size_t i = 0; i < grid.size(); i++) {
      for (size_t j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          for (size_t k = 0; k < 4; k++) {  // 上下左右四个方向
            int x = i + direction[k][0];
            int y = j + direction[k][1];     // 计算周边坐标x,y
            if (x < 0                        // i在边界上
                || x >= int(grid.size())     // i在边界上
                || y < 0                     // j在边界上
                || y >= int(grid[0].size())  // j在边界上
                || grid[x][y] == 0) {        // x,y位置是水域
              result++;
            }
          }
        }
      }
    }
    return result;
  }
};

TEST(lc_0463, lc_0463) { Solution s; }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
