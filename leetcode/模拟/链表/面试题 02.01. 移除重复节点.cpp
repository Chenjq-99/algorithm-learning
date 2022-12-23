#include<iostream>
using namespace std;

int main(){
    return 0;
}

/**
 * https://leetcode-cn.com/problems/remove-duplicate-node-lcci/
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {

        if(head == NULL || head->next == NULL){return head;}

        ListNode* cur = head;

        while(cur != NULL)
        {
            ListNode* cur2 = cur;

            while(cur2->next != NULL)
            {
                if(cur2->next->val == cur->val)
                {
                    cur2->next = cur2->next->next;
                }
                else
                {
                    cur2 = cur2->next;
                }                
            }
            cur = cur->next;
        }

        return head;
        


        // ตÝน้

        // ListNode* newHead = removeDuplicateNodes(head->next);

        // head->next = newHead;

        // ListNode* cur = newHead;

        // if(cur->val == head->val){return newHead;}

        // while(cur->next != NULL)
        // {
        //     if(cur->next->val == head->val)
        //     {
        //         cur->next = cur->next->next;
        //         break;
        //     }
        //     cur = cur->next;                      
        // }

        // return head;
    }
};