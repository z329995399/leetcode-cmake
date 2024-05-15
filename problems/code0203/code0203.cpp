#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
  ListNode* dummy = new ListNode(0);
  dummy->next = head;

  ListNode* pre = dummy;
  ListNode* cur = head;

  while (cur != nullptr) {
    if (cur->val == val) {
      // tmp
      ListNode* tmp = pre->next;
      // link
      pre->next = cur->next;
      // move
      delete cur;
      cur = tmp;
    } else {
      pre = cur;
      cur = cur->next;
    }
  }

  return dummy->next;
}

void printList(ListNode* head) {
  ListNode* curr = head;
  while (curr != nullptr) {
    std::cout << curr->val << " -> ";
    curr = curr->next;
  }
  std::cout << "nullptr" << std::endl;
}

int main() {
  // 创建链表: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next->next = new ListNode(6);

  std::cout << "原始链表: ";
  printList(head);

  int val = 6;
  ListNode* newHead = removeElements(head, val);

  std::cout << "移除值为 " << val << " 的节点后的链表: ";
  printList(newHead);

  // 释放链表内存
  ListNode* curr = newHead;
  while (curr != nullptr) {
    ListNode* tmp = curr;
    curr = curr->next;
    delete tmp;
  }

  return 0;
}
