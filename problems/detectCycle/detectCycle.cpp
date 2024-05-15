#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            break;
        }

    }

    if (fast == nullptr || fast->next == nullptr)
    {
        return nullptr;
    }

    ListNode* ptr = head;
    while (ptr != slow)
    {
        ptr = ptr->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    // 创建链表
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // 构造环

    // 判断是否有环，并返回环的起始节点
    ListNode *cycleStart = detectCycle(head);
    if (cycleStart != nullptr) {
        std::cout << "链表有环，环的起始节点值为: " << cycleStart->val << std::endl;
    } else {
        std::cout << "链表无环。" << std::endl;
    }

    return 0;
}
