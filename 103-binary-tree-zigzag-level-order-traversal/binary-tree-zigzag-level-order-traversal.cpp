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
    void zigzagBFS(TreeNode*root,vector<vector<int>>&ans){
        int level=0;
        if(!root) return;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            level++;
            vector<int>temp;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                temp.push_back(node->val);
            }
            if(level%2==0){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        zigzagBFS(root,ans);
        return ans;
    }
};