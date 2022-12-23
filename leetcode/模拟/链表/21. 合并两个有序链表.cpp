#include<iostream>
using namespace std;

int main(){
    return 0;
}
/**
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL){return list2;}
        if(list2 == NULL){return list1;}

        ListNode*p1 = list1->val >= list2->val ? list2 : list1;

        ListNode*p2 = list1->val < list2->val ? list2 : list1;

        // µÝ¹é

        // ListNode* newList = mergeTwoLists(p1->next,p2);

        // p1->next = newList;

        // return p1;

        // µü´ú

        ListNode* newList = p1;

        ListNode* newList = p1;

        while(p1 != NULL && p2 != NULL)
        {
            if(p1->next != NULL)
            {
                if(p1->val <= p2->val && p2->val <= p1->next->val)
                {
                    ListNode* temp = p2;
                    p2 = p2->next;
                    ListNode* next = p1->next;
                    p1->next = temp;
                    temp->next = next;
                }
                else
                {
                    p1 = p1->next;
                }
            }
            else
            {
                 p1->next = p2;
                 break;
            }
        }
        return newList;                   
    }
};