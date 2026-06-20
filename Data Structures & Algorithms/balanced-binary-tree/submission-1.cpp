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
    bool ans=true;
    bool isBalanced(TreeNode* root) {
        maxh(root);
        return ans;
    }

    int maxh(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int height1=maxh(root->left);
        int height2=maxh(root->right);
        if(abs(height1-height2)>1){ans=false;}

        return max(height1,height2)+1;
    }
};
