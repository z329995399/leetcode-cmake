#include <iostream>
#include <vector>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    std::cout << std::endl;

    if (obstacleGrid.empty()) {
        return 0;
    }

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
        return 0;
    }

    std::vector<std::vector<int>> dp(m, std::vector<int>(n));

    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1) {
            break;
        }

        dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] == 1) {
            break;
        }

        dp[0][i] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] != 1) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return dp[m-1][n-1];
}

int main() {
    std::vector<std::vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    std::cout << "Number of unique paths: " << uniquePathsWithObstacles(obstacleGrid) << std::endl;

    return 0;
}
