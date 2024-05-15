#include "headers.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  ListNode* reverseList(ListNode* head) {
    ListNode* tmp;
    ListNode* cur = head;
    ListNode* pre = nullptr;

    while (cur) {
      tmp = cur->next;
      cur->next = pre;

      pre = cur;
      cur = tmp;
    }

    return pre;
  }
};
// TEST(lc_0206, lc_0206) { Solution s; }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
