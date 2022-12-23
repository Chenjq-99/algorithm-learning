#include<iostream>
using namespace std;

/**
 * https://leetcode-cn.com/problems/reverse-linked-list/
 * Definition for singly-linked list. 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* p0 = dummy;
        for (int i = 0; i < left - 1; i++) p0 = p0->next;
        ListNode* pre = nullptr;
        ListNode* cur = p0->next;
        ListNode* nxt = nullptr;
        for (int i = 0; i <= right - left; i++) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        p0->next->next = cur;
        p0->next = pre;
        return dummy->next;
    }
};