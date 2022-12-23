#include<iostream>
using namespace std;

int main(){
    return 0;
}

/**
 * https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
 * Definition for singly-linked list.
 */

struct ListNode { 
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {

        if(head == NULL){return head;}

        // µü´ú

        if(head->val == val){return head->next;}

        ListNode* cur = head;

        while(cur->next!=NULL)
        {
            if(cur->next->val == val)
            {
                cur->next = cur->next->next;
                break;
            }
            cur = cur->next;
        }

        return head;


        // µÝ¹é

        // ListNode* newHead = deleteNode(head->next,val);

        // head->next = newHead;

        // return head->val == val ? newHead : head;

    }
};