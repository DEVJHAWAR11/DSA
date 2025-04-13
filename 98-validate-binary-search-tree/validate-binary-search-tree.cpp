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

    bool solve(TreeNode*root,long long int lb,long long int rb){
        if(root==NULL) return true;

        bool cond1=(root->val>lb);
        bool cond2=(root->val<rb);
        bool leftAns=solve(root->left,lb,root->val);
        bool rightAns=solve(root->right,root->val,rb);

        if(cond1 && cond2 && leftAns && rightAns) return true;
        else return false;
    }

    bool isValidBST(TreeNode* root) {
        long long int lb=-2147483658;
        long long int rb=2147483657;

        bool ans=solve(root,lb,rb);
        return ans;
    }
};