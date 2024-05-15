#include "headers.h"

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> result(nums1.size(), -1);
    std::stack<int> st;  // nums2 index

    std::unordered_map<int, int> umap;
    for (size_t i = 0; i < nums1.size(); i++) {
      umap[nums1[i]] = i;
    }

    st.push(0);

    for (size_t i = 1; i < nums2.size(); i++) {
      while (!st.empty() && nums2[i] > nums2[st.top()]) {
        if (umap.find(nums2[st.top()]) != umap.end()) {
          int num1_index = umap[nums2[st.top()]];
          result[num1_index] = nums2[i];
        }

        st.pop();
      }

      st.push(i);
    }

    return result;
  }
};
TEST(lc_0496, lc_0496) {
  Solution s;
  std::vector<int> nums1 = {4, 1, 2};
  std::vector<int> nums2 = {1, 3, 4, 2};
  std::vector<int> res = {-1, 3, -1};

  EXPECT_EQ(s.nextGreaterElement(nums1, nums2), res);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
