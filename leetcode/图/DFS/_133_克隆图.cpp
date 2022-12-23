#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/clone-graph/
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    Node* visited[101] = {nullptr};
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node* newNode = new Node(node->val,vector<Node*> {});
        visited[node->val] = newNode;
        for(int i = 0; i < node->neighbors.size(); i++){
            if(!visited[node->neighbors[i]->val]){
                newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }else{
                newNode->neighbors.push_back(visited[node->neighbors[i]->val]);
            }
        }
        return newNode;
    }
};