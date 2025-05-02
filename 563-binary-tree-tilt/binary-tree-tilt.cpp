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
private:
    int tilt(TreeNode*root,int &sum){
        if(!root) return 0;

        int lval=tilt(root->left,sum);
        int rval=tilt(root->right,sum);
        int diff=abs(lval-rval);
        sum+=diff;
        return lval+rval+root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int sum=0;
        tilt(root,sum);
        return sum;
    }
};