#include "headers.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (n-- && fast) {
      fast = fast->next;
    }

    // one more step
    fast = fast->next;

    while (slow && fast) {
      slow = slow->next;
      fast = fast->next;
    }

    slow->next = slow->next->next;

    return head;
  }

  void printList(ListNode* head) {
    ListNode* cur = head;

    while (cur != nullptr) {
      std::cout << cur->val << "->";
      cur = cur->next;
    }

    std::cout << std::endl;
  }
};
TEST(lc_0019, lc_0019) {
  Solution s;
  ListNode* c_head = new ListNode(1);
  c_head->next = new ListNode(2);
  c_head->next->next = new ListNode(3);
  c_head->next->next->next = new ListNode(4);
  c_head->next->next->next->next = new ListNode(5);
  c_head->next->next->next->next->next = new ListNode(6);

  s.printList(c_head);

  ListNode* remove_n_head = s.removeNthFromEnd(c_head, 4);

  s.printList(remove_n_head);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
