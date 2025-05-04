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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key < root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key > root->val) {
            root->right=deleteNode(root->right,key);
        }
        else{
            //key found
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(!root->left || !root->right){
                TreeNode* temp =root->left!=NULL? root->left : root->right;
                delete root;
                return temp;
            }
            else{
                TreeNode* max=root->left;
                while(max->right) max=max->right;
                root->val=max->val;
                root->left=deleteNode(root->left,max->val);
            }
        }
        return root;
    }
};