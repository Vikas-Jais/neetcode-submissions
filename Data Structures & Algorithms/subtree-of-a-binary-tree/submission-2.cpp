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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> arr;
        Traversal(root,arr);
        vector<int> subarr;
        Traversal(subRoot,subarr);
        vector<int> lps=Buildlps(subarr);

        return Match(arr,subarr,lps);
    }

    void Traversal(TreeNode* root,vector<int> &res){
        if(root==nullptr){
            res.push_back(-101);
            return;
        }
        res.push_back(root->val);
        Traversal(root->left,res);
        Traversal(root->right,res);
    }

    vector<int> Buildlps(vector<int> &subarr){
        int len=0;
        vector<int> lps(subarr.size(),0);
        lps[0]=0;
        int i=1;
        while(i<subarr.size()){
            if(subarr[len]==subarr[i]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len){
                    len=lps[len-1];
                }
                else{
                    i++;
                }
            }
        }
        return lps;
    }

    bool Match(vector<int> &arr,vector<int> &subarr,vector<int> &lps){
        int i=0;
        int j=0;
        while(i<arr.size()){
            if(arr[i]==subarr[j]){
                i++;
                j++;
                if(j==subarr.size()){
                    return true;
                }   
            }
            else{
                if(j){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }
};
