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
  bool hasCircle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (fast == slow) {
        return true;
      }
    }

    return false;
  }

  ListNode* detectCircle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (fast == slow) {
        ListNode* index1 = head;
        ListNode* index2 = slow;

        while (index1 != index2) {
          index1 = index1->next;
          index2 = index2->next;
        }

        return index2;
      }
    }

    return nullptr;
  }
};

TEST(lc_0141, lc_0141) {
  Solution s;
  ListNode* c_head = new ListNode(1);
  c_head->next = new ListNode(2);
  c_head->next->next = new ListNode(3);
  c_head->next->next->next = new ListNode(4);

  c_head->next->next->next = c_head->next->next;

  std::cout << "circle: " << s.hasCircle(c_head) << std::endl;

  ListNode* in_circle_node = s.detectCircle(c_head);

  if (in_circle_node != nullptr) {
    std::cout << "in_circle_node: " << in_circle_node->val << std::endl;
  }

  EXPECT_EQ(s.hasCircle(c_head), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
