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
    int maxDepth(TreeNode* root) {
        int depth=0;

        //DFS
        // if(root==NULL){
        //     return 0;
        // }
        // int leftH=maxDepth(root->left);
        // int rightH= maxDepth(root->right);
        // return max(leftH ,rightH)+1;


        //BFS
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            depth++;
            while(size--){
                auto node=q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return depth;
    }
};