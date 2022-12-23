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
    // ListNode* reverseList(ListNode* head) {

    //     // µÝ¹é

    //     if(head == NULL||head->next == NULL){return head;}
        

    //     ListNode* newHead = reverseList(head->next);

    //     head->next->next = head;
        
    //     head->next = NULL;

    //     return newHead;
    // }
    ListNode* reverseList(ListNode* head) {

        // µü´ú

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = nullptr;
        while (cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

int main(){
    return 0;
}