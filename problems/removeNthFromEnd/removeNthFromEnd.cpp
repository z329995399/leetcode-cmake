#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) {
        return nullptr;
    }

    ListNode* tmp = new ListNode(0);
    tmp->next = head;

    ListNode* fast = tmp;
    ListNode* slow = tmp;

    for (int i = 0; i <= n; i++) {
        if (!fast) {
            return nullptr;
        }

        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* del = slow->next;
    slow->next = slow->next->next;
    delete del;

    return tmp->next;

}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example input: 1->2->3->4->5, n = 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    std::cout << "Original list: ";
    printList(head);

    ListNode* newHead = removeNthFromEnd(head, n);

    std::cout << "List after removing " << n << "th node from end: ";
    printList(newHead);

    // Clean up the memory
    while (newHead) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
