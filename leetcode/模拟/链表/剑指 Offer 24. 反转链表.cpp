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

    //     // µİ¹é

    //     if(head == NULL||head->next == NULL){return head;}
        

    //     ListNode* newHead = reverseList(head->next);

    //     head->next->next = head;
        
    //     head->next = NULL;

    //     return newHead;
    // }
    ListNode* reverseList(ListNode* head) {

        // µü´ú

        if(head == NULL||head->next == NULL){return head;}

        ListNode* temp = NULL;

        ListNode* newHead = NULL;
        
        while (head != NULL)
        {
             temp = head->next;

             head->next = newHead;

             newHead = head;

             head = temp;
        }
        return newHead;
    }
};

int main(){
    return 0;
}