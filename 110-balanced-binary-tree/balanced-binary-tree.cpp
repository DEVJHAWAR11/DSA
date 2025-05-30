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

    int height(TreeNode* root){
        if(root==NULL) return 0;

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int Height=max(leftHeight,rightHeight)+1;
        return Height;
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int leftH=height(root->left);
        int rightH=height(root->right);
        int diff=abs(leftH-rightH);

        bool diffans=(diff<=1);

        bool leftAns=isBalanced(root->left);
        bool rightAns=isBalanced(root->right);
        if(diffans && leftAns && rightAns) return true;
        else return false;
    }
};