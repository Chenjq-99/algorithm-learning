#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
// https://leetcode.cn/problems/n-ary-tree-preorder-traversal/


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};

        stack<Node*> s;
        s.push(root);
        vector<int> res;
        Node* node = root;
        while(!s.empty()){
            node = s.top();
            s.pop();
            res.push_back(node->val);
            if(!node->children.empty()){
                reverse(node->children.begin(),node->children.end());
                for(vector<Node*>::iterator it = node->children.begin(); it!= node->children.end(); it++){
                    if(*it) s.push(*it);
                }
            }
        }
        return res;
    }
};

int main(){
    return 0;
}