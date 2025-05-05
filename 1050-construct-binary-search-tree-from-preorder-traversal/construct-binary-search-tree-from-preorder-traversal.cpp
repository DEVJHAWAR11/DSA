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

//BRUTE FORCE(O(N2))
// class Solution {
// public:

//     TreeNode* insert(TreeNode* root,int data){
//         if(!root) return new TreeNode(data);

//         if(data < root->val){
//             root->left=insert(root->left,data);
//         }
//         else{
//             root->right=insert(root->right,data);
//         }
//         return root;
//     }

//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         TreeNode*root=NULL;
//         for(auto val : preorder){
//             root=insert(root,val);
//         }
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* helper(int &i,int min,int max,vector<int>&preorder){
        if(i==preorder.size()||preorder[i]<min || preorder[i]>max) return NULL;
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=helper(i,min,root->val,preorder);
        root->right=helper(i,root->val,max,preorder);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        TreeNode*root=helper(i,INT_MIN,INT_MAX,preorder);
        return root;
    }
};