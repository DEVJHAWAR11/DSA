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
    
    int height(TreeNode*root,int &D){
        if(root==NULL) return 0;

        int lh=height(root->left,D);
        int rh=height(root->right,D);

        int currD=lh+rh;
        D=max(currD,D);      //keeping track of diamter of each node
        return max(lh,rh)+1; //returning height of lh rh for each node for D

    }

    int diameterOfBinaryTree(TreeNode* root) {
        int D=0;
        height(root,D);
        return D;
    }
};