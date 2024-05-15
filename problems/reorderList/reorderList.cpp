#include <iostream>
#include <deque>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void reorderList(ListNode* head) {
    std::deque<ListNode*> que;
    ListNode* cur = head;
    if (cur == nullptr) return;

    while(cur->next != nullptr) {
        que.push_back(cur->next);
        cur = cur->next;
    }

    for (size_t i = 0; i < que.size(); i++)
    {
        std::cout << que[i]->val << std::endl;
    }

    cur = head;
    int count = 0; // 计数，偶数去后面，奇数取前面
    ListNode* node;
    while(que.size()) {
        if (count % 2 == 0) {
            node = que.back();
            que.pop_back();
        } else {
            node = que.front();
            que.pop_front();
        }
        count++;
        cur->next = node;
        cur = cur->next;
    }
    cur->next = nullptr; // 注意结尾
}

void printList(ListNode* head) {
    ListNode* p = head;
    while (p != nullptr) {
        std::cout << p->val << " -> ";
        p = p->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // 创建链表
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    std::cout << "原始链表: ";
    printList(head);

    // 重排链表
    reorderList(head);

    std::cout << "重排后链表: ";
    printList(head);

    return 0;
}
