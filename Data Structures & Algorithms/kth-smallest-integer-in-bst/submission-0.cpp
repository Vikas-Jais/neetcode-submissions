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
    int ans=0;
    int count=0;
    int kthSmallest(TreeNode* root, int k) {
        kNode(root,k);
        return ans;
    }

    void kNode(TreeNode* root,int k){
        if(!root){
            return;
        }

        kNode(root->left,k);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        kNode(root->right,k);
    }
};
