#include<iostream>
using namespace std;
#include<vector>

int main(){
    return 0;
}
/**
 * https://leetcode-cn.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {

        vector<int> v;

        while (head != NULL)
        {
            v.push_back(head->val);
            head = head->next;
        }

        for(int i = 0,j = v.size()-1;i<j;i++,j--)
        {
            if(v[i] != v[j])
            {
                return false;
            }
        }

        return true;      

        
    }
};