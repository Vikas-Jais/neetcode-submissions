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
    int mine=INT_MIN;
    int maxe=INT_MAX;
    bool isValidBST(TreeNode* root) {
        return valid(root,mine,maxe);
    }

    bool valid(TreeNode* root, int min, int max){
        if(!root){
            return true;
        }
        if(root->val<=min || root->val>=max){
            return false;
        }
        bool left= valid(root->left,min,root->val);
        bool right=valid(root->right,root->val,max);
        if(!left || !right)return false;
        else return true;
    }
};
