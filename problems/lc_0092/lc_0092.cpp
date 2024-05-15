#include "headers.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseLinkedList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;

    while (cur != nullptr) {
      // tmp
      ListNode *tmp = cur->next;
      // link
      cur->next = pre;
      // move
      pre = cur;
      cur = tmp;
    }

    return pre;
  }

  void printList(ListNode *head) {
    ListNode *cur = head;

    while (cur != nullptr) {
      std::cout << cur->val << "->";
      cur = cur->next;
    }

    std::cout << std::endl;
  }

 public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    // find left
    ListNode *left_node = nullptr;
    ListNode *cur = dummy;
    for (int i = 0; i < left; i++) {
      left_node = cur;
      cur = cur->next;
    }

    ListNode *pre_left = left_node;
    left_node = left_node->next;
    std::cout << "left: " << left << " val: " << left_node->val << std::endl;

    // find right
    ListNode *right_node = nullptr;
    for (int i = 0; i < right - left + 1; i++) {
      right_node = cur;
      cur = cur->next;
    }

    ListNode *next_right = right_node->next;
    std::cout << "right: " << right << " val: " << right_node->val << std::endl;

    // unlink
    pre_left->next = nullptr;
    right_node->next = nullptr;

    // reverse
    ListNode *reversed_head = reverseLinkedList(left_node);

    // link
    pre_left->next = reversed_head;
    left_node->next = next_right;

    return dummy->next;
  }
};

TEST(lc_0092, lc_0092) {
  Solution s;

  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  std::cout << "before reverse: ";
  s.printList(head);

  ListNode *reversed_head = s.reverseBetween(head, 2, 4);

  // ListNode *reversed_head = s.reverseLinkedList(head);

  std::cout << "after reverse: ";
  s.printList(reversed_head);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
