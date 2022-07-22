#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode m;
        ListNode* cur = &m;

        ListNode* p1 = list1;
        ListNode* p2 = list2;
        if (!p1 && !p2)
            return m.next;

        while (p1 && p2) {
            if (p1->val <= p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else if (p1->val > p2->val) {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }

        while (p1) {
            cur->next = p1;
            p1 = p1->next;
            cur = cur->next;
        }

        while (p2) {
            cur->next = p2;
            p2 = p2->next;
            cur = cur->next;
        }

        return m.next;
    }

    void test() {
        ListNode* a;
        ListNode* b; 
        ListNode* merged;
        a = new ListNode(1, new ListNode(2, new ListNode(4)));
        b = new ListNode(1, new ListNode(3, new ListNode(4)));

        merged = mergeTwoLists(a, b);
        printLinkedlist(merged);
    }

    void test2() {
        ListNode* a = nullptr;
        ListNode* b = nullptr; 
        ListNode* merged;

        merged = mergeTwoLists(a, b);
        printLinkedlist(merged);
    }

    void test3() {
        ListNode* a = nullptr;
        ListNode* b; 
        ListNode* merged;
        b = new ListNode(0);

        merged = mergeTwoLists(a, b);
        printLinkedlist(merged);
    }

private:
    void printLinkedlist(ListNode* ptr) {
        ListNode* p = ptr;
        while (p) {
            std::cout << p->val << "\t";
            p = p->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;
    s.test();
    s.test2();
    s.test3();
    return 0;
}
