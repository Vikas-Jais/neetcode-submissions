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
    int diameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxh(root);
        return diameter;
    }
    int maxh(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int height1=maxh(root->left);
        int height2=maxh(root->right);
        diameter=max(diameter,height1+height2);

        return max(height1,height2)+1;
    }
};
