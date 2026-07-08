/*
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
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(node->neighbors.empty()){
            Node* head=new Node(node->val);
            return head;
        }
        Node* ans=dfs(node);
        return ans;
    }

    Node* dfs(Node* node){
        if(mp.count(node)){
            return mp[node];
        }
        Node* newnode=new Node(node->val);
        mp[node]=newnode;
        for(auto it:node->neighbors){
            Node*child=dfs(it);
            newnode->neighbors.push_back(child);
        }
        return newnode;
    }
};
