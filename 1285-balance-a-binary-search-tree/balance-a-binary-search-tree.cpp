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
    void inorder(TreeNode*root,vector<int>&in){
        if(!root) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }

    TreeNode* helper(int s,int e,vector<int>&in){
        if(s>e) return NULL;

        int mid=(s+e)/2;
        TreeNode*root=new TreeNode(in[mid]);
        root->left=helper(s,mid-1,in);
        root->right=helper(mid+1,e,in);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);

        return helper(0,in.size()-1,in);
    }
};