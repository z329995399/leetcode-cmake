#include "headers.h"

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i++) sum += nums[i];
    if (abs(S) > sum) return 0;        // 此时没有方案
    if ((S + sum) % 2 == 1) return 0;  // 此时没有方案
    int bagSize = (S + sum) / 2;
    std::cout << "bagSize: " << bagSize << std::endl;
    vector<int> dp(bagSize + 1, 0);
    dp[0] = 1;
    for (size_t i = 0; i < nums.size(); i++) {
      std::cout << "i: " << i << std::endl;
      for (int j = bagSize; j >= nums[i]; j--) {
        dp[j] += dp[j - nums[i]];

        std::cout << dp[j - nums[i]] << " " << j - nums[i] << " " << nums[i]
                  << "|";
      }

      std::cout << std::endl;

      for (int i = 0; i <= bagSize; i++) {
        std::cout << dp[i] << " ";
      }

      std::cout << std::endl;
    }
    return dp[bagSize];
  }
};
TEST(lc_0494, lc_0494) {
  Solution s;
  std::vector<int> nums = {1, 1, 1, 1, 1};
  int target = 3;
  EXPECT_EQ(s.findTargetSumWays(nums, target), 5);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
