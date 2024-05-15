#include "headers.h"

using std::vector;

class Solution {
 private:
  std::vector<std::vector<int>> result;
  std::vector<int> path;

  void backtracking(std::vector<int> nums, int start_index) {
    if (path.size() > 1) {
      result.push_back(path);
    }

    std::unordered_set<int> uset;

    for (size_t i = start_index; i < nums.size(); i++) {
      if ((!path.empty() && nums[i] < path.back()) ||
          (uset.find(nums[i]) != uset.end())) {
        continue;
      }

      uset.insert(nums[i]);
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

 public:
  Solution(/* args */);
  ~Solution();

  vector<vector<int>> findSubsequences(vector<int>& nums) {
    result.clear();
    path.clear();
    backtracking(nums, 0);
    return result;
  }
};

Solution::Solution(/* args */) {}

Solution::~Solution() {}

TEST(lc_0491, lc_0491) { Solution s; }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
