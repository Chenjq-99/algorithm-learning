#include<iostream>
using namespace std;

int main(){
    return 0;
}
/**
 * https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* l1 = headA;
        ListNode* l2 = headB;
        ListNode* lA= headA;
        ListNode* lB = headB;

        while(l1 != NULL && l2 != NULL){l1 = l1->next;l2 = l2->next;}

        while(l1 != NULL){l1 = l1->next;lB = lB->next;}

        while(l2 != NULL){l2 = l2->next;lA = lA->next;}

        while(lA != NULL && lB != NULL)
        {
            if(lA == lB)
            {
                return lA;
            }

            lA = lA->next;
            lB = lB->next;
        } 
        return NULL;
        
        // 我走过你来时的路
        // while (l1!= l2) {
        //     l1 = l1 != nullptr ? l1->next : headB;
        //     l2 = l2 != nullptr ? l2->next : headA;
        // }
        // return l1;

        
    }
};