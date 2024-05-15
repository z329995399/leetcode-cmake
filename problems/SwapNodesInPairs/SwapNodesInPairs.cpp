#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
        return nullptr;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cur = dummy;

    while (cur->next && cur->next->next) {
        ListNode* tmp1 = cur->next;
        ListNode* tmp2 = cur->next->next->next;

        // step 1
        cur->next = cur->next->next;
        // step 2
        cur->next->next = tmp1;
        // step 3
        cur->next->next->next = tmp2;

        // move
        cur = cur->next->next;
    }

    ListNode* res = dummy->next;
    delete dummy;
    return res;

}

// ListNode* swapPairs(ListNode* head) {
//     ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
//     dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
//     ListNode* cur = dummyHead;
//     while(cur->next != nullptr && cur->next->next != nullptr) {
//         ListNode* tmp = cur->next; // 记录临时节点
//         ListNode* tmp1 = cur->next->next->next; // 记录临时节点

//         cur->next = cur->next->next;    // 步骤一
//         cur->next->next = tmp;          // 步骤二
//         cur->next->next->next = tmp1;   // 步骤三

//         cur = cur->next->next; // cur移动两位，准备下一轮交换
//     }
//     ListNode* result = dummyHead->next;
//     delete dummyHead;
//     return result;
// }

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example input: 1->2->3->4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    std::cout << "Original list: ";
    printList(head);

    ListNode* newHead = swapPairs(head);

    std::cout << "List after swapping pairs: ";
    printList(newHead);

    // Clean up the memory
    while (newHead) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
