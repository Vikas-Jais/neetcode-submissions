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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serial(root,s);
        return s;
    }

    void serial(TreeNode* root,string& s){
        if(!root){
            s.append("#");
            s.append(",");
            return;
        }
        s.append(to_string(root->val));
        s.append(",");
        serial(root->left,s);
        serial(root->right,s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return deserial(data,i);
    }

    TreeNode* deserial(string& s,int& i){
        string k;
        while(s[i]!=','){
            k+=s[i];
            i++;
        }
        if(k=="#"){
            i++;
            return nullptr;
        }
        TreeNode* node=new TreeNode(stoi(k));
        i++;
        node->left=deserial(s,i);
        node->right=deserial(s,i);
        return node;
    }
};

