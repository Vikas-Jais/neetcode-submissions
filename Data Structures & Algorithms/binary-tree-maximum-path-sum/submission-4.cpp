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
    int maxPathSum(TreeNode* root) {
        int sum=root->val;
        pathsum(root,sum);
        return sum;
    }

    int pathsum(TreeNode* root, int& sum){
        if(!root){
            return 0;
        }
        int left=pathsum(root->left,sum);
        int right=pathsum(root->right,sum);
        if(left<0) left=0;
        if(right<0) right=0;
        sum=max(sum,root->val+left+right);
        return root->val+max(left,right);
    }
};
