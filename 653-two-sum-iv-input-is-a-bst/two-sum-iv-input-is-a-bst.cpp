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

    void solveInorder(TreeNode*root,vector<int>&inorder){
        if(root==NULL) return;

        solveInorder(root->left,inorder);

        inorder.push_back(root->val);

        solveInorder(root->right,inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        solveInorder(root,inorder);

        int s=0;
        int e=inorder.size()-1;
        while(s<e){
            if(inorder[s]+inorder[e]==k) return true;

            else if(inorder[s]+inorder[e]<k) s++;
            else e--;
        }
        return false;
    }
};