/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // if(root==NULL) return NULL;

        // // if(p->val<root->val && q->val > root->val){
        // //     return root;
        // // }

        // // if(p->val > root->val && q->val < root->val){
        // //     return root;
        // // }

        // if(p->val < root->val && q->val < root->val){
        //     return lowestCommonAncestor(root->left,p,q);
        // }

        // if(p->val > root->val && q->val > root->val){
        //     return lowestCommonAncestor(root->right,p,q);
        // }
        
        // return root;

        while (root) {
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else {
                return root;
            }
        }
        return nullptr; 

    }
};