#include "headers.h"

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(-1), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
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

  void printList(ListNode* head) {
    ListNode* cur = head;

    while (cur != nullptr) {
      std::cout << cur->val << "->";
      cur = cur->next;
    }

    std::cout << std::endl;
  }

  ListNode* reorderList(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    // split
    ListNode* head1 = head;
    ListNode* head2 = slow->next;

    // unlink
    slow->next = nullptr;

    std::cout << "head1: ";
    printList(head1);

    std::cout << "head2: ";
    printList(head2);

    // reverse head2
    head2 = reverseList(head2);

    std::cout << "reversed head2: ";
    printList(head2);

    // merge head1 and head2
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    int count = 0;

    while (head1 && head2) {
      if (count % 2 == 0) {
        cur->next = head1;
        head1 = head1->next;
      } else {
        cur->next = head2;
        head2 = head2->next;
      }

      count++;
      cur = cur->next;
    }

    cur->next = head1 ? head1 : head2;

    return dummy->next;
  }
};
TEST(lc_0143, lc_0143) {
  Solution s;
  ListNode* c_head = new ListNode(1);
  c_head->next = new ListNode(2);
  c_head->next->next = new ListNode(3);
  c_head->next->next->next = new ListNode(4);
  c_head->next->next->next->next = new ListNode(5);
  // c_head->next->next->next->next->next = new ListNode(6);

  ListNode* reordered_list = s.reorderList(c_head);

  s.printList(reordered_list);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
