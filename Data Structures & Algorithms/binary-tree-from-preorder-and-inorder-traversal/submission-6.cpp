/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int curr=0;
        return Build(preorder,inorder,curr,0,preorder.size()-1);
    }

    TreeNode* Build(vector<int>& preorder,vector<int>& inorder,int& curr,int left,int right){
        if(curr>=preorder.size() || left>right) return nullptr;
        int x=preorder[curr];
        TreeNode* root=new TreeNode(preorder[curr]);
        curr++;
        if(left==right)return root;

        root->left=Build(preorder,inorder,curr,left,mp[x]-1);
        root->right=Build(preorder,inorder,curr,mp[x]+1,right);
        
        return root;        
    }
};
