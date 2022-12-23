#include<iostream>
using namespace std;

int main(){
    return 0;
}

/**
 * https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
};
class Solution {
public:
    int kthToLast(ListNode* head, int k) {

        ListNode* first = head;
        ListNode* second = head;

        for(int i = 0;i < k;i++)
        {
            second = second->next;
        }

        while(second != NULL)
        {
            first = first->next;
            second = second->next;
        }

        return first->val;

    }
};