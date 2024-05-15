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
  ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode* head = new ListNode(-1);
    ListNode* cur = head;

    while (a != nullptr && b != nullptr) {
      if (a->val <= b->val) {
        cur->next = a;
        a = a->next;
      } else {
        cur->next = b;
        b = b->next;
      }

      cur = cur->next;
    }

    cur->next = a != nullptr ? a : b;
    return head->next;
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

TEST(lc_0021, lc_0021) {
  Solution s;
  ListNode* head1 = new ListNode(0);
  head1->next = new ListNode(1);
  head1->next->next = new ListNode(6);

  ListNode* head2 = new ListNode(2);
  head2->next = new ListNode(3);
  head2->next->next = new ListNode(6);

  std::cout << "list1: ";
  s.printList(head1);

  std::cout << "list2: ";
  s.printList(head2);

  ListNode* merged_head = s.mergeTwoLists(head1, head2);

  std::cout << "merged list: ";
  s.printList(merged_head);

  EXPECT_EQ(merged_head->val, head1->val);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
