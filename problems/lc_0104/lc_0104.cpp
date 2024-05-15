#include "headers.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int getDepth(TreeNode* root) {
    if (!root) return 0;
    int left = getDepth(root->left);
    int right = getDepth(root->right);
    return std::max(left, right) + 1;
  }

  void printTree(TreeNode* root) {
    if (!root) {
      return;
    }

    std::string left_str =
        root->left ? std::to_string(root->left->val) : "null";
    std::string right_str =
        root->right ? std::to_string(root->right->val) : "null";
    std::cout << "root: " << root->val << " left: " << left_str
              << " right: " << right_str << std::endl;

    if (root->left) {
      printTree(root->left);
    }

    if (root->right) {
      printTree(root->right);
    }
  }
};

TEST(lc_0104, lc_0104) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);

  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);

  // root->left->left->left = new TreeNode(5);
  // root->left->left->right = new TreeNode(6);

  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  // root->right->right->left = new TreeNode(5);
  // root->right->right->right = new TreeNode(5);

  s.printTree(root);

  std::cout << "max depth: " << s.getDepth(root) << std::endl;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
