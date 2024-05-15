#include "headers.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    std::stack<TreeNode*> st;
    if (root) {
      st.push(root);
    } else {
      return root;
    }

    while (!st.empty()) {
      TreeNode* t = st.top();
      st.pop();
      swap(t->left, t->right);
      if (t->left) {
        st.push(t->left);
      }
      if (t->right) {
        st.push(t->right);
      }
    }

    return root;
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
TEST(lc_0226, lc_0226) {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);

  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);

  s.printTree(root);

  TreeNode* invert_tree = s.invertTree(root);

  std::cout << "invert tree: " << std::endl;
  s.printTree(invert_tree);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
