#include "headers.h"

struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  int val;
};

class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    int result = 0;
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; i++) {
        TreeNode* node = que.front();
        que.pop();
        if (i == 0) result = node->val;  // 记录最后一行第一个元素
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
    }
    return result;
  }
};
TEST(lc_0513, lc_0513) { Solution s; }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
