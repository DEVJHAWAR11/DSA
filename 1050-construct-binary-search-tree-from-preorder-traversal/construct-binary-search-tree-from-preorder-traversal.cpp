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

    TreeNode* insert(TreeNode* root,int data){
        if(!root) return new TreeNode(data);

        if(data < root->val){
            root->left=insert(root->left,data);
        }
        else{
            root->right=insert(root->right,data);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=NULL;
        for(auto val : preorder){
            root=insert(root,val);
        }
        return root;
    }
};