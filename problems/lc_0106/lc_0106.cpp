#include "headers.h"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* traversal(const std::vector<int>& inorder,
                      const std::vector<int>& postorder) {
    if (postorder.size() == 0) return nullptr;
    TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);

    if (postorder.size() == 1) return root;

    int split_idx = -1;
    int split_val = postorder[postorder.size() - 1];

    for (size_t i = 0; i < inorder.size(); i++) {
      if (inorder[i] == split_val) {
        split_idx = int(i);
        break;
      }
    }

    if (split_idx == -1) return nullptr;

    std::cout << "root: " << root->val << std::endl;

    std::vector<int> left_inorder(inorder.begin(), inorder.begin() + split_idx);
    std::vector<int> right_inorder(inorder.begin() + split_idx + 1,
                                   inorder.end());
    std::cout << "left_inorder: ";
    printVector(left_inorder);

    std::cout << "right_inorder: ";
    printVector(right_inorder);

    std::vector<int> left_postorder(postorder.begin(),
                                    postorder.begin() + left_inorder.size());
    std::vector<int> right_postorder(postorder.begin() + left_inorder.size(),
                                     postorder.end() - 1);

    std::cout << "left_postorder: ";
    printVector(left_postorder);

    std::cout << "right_postorder: ";
    printVector(right_postorder);

    root->left = traversal(left_inorder, left_postorder);
    root->right = traversal(right_inorder, right_postorder);

    return root;
  }

  void printVector(const std::vector<int>& x) {
    for (size_t i = 0; i < x.size(); i++) {
      std::cout << x[i] << " ";
    }
    std::cout << std::endl;
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
TEST(lc_0106, lc_0106) {
  Solution s;
  std::vector<int> inorder = {9, 3, 15, 20, 7};
  std::vector<int> postorder = {9, 15, 7, 20, 3};
  TreeNode* root = s.traversal(inorder, postorder);

  s.printTree(root);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
