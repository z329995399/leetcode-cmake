#include "headers.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool compare(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (left && !right) return false;
    if (!left && right) return false;
    if (left->val != right->val) return false;

    // left->val == right->val
    bool inside = compare(left->right, right->left);
    bool outside = compare(left->left, right->right);
    return inside && outside;
  }

  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return compare(root->left, root->right);
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
TEST(lc_0101, lc_0101) {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);

  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);

  root->left->left->left = new TreeNode(5);
  root->left->left->right = new TreeNode(6);

  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  root->right->right->left = new TreeNode(5);
  root->right->right->right = new TreeNode(5);

  s.printTree(root);

  std::cout << "is symmetric: " << s.isSymmetric(root) << std::endl;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
