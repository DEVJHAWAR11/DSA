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
    bool isCompleteTree(TreeNode* root) {
        //ek null ke baad ek notnull nhi aana chahiye agar aaya toh not complete
        //toh keep adding in queue jab tak pehla null nhi mil jaata
        //after that keep popping all null from queue
        //if at last we get a empty queue -->then complete else not
        queue<TreeNode*>q;
        q.push(root);
        while(q.front()){
            TreeNode* node=q.front();
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        while(!q.empty()&& !q.front()){
            q.pop();
        }
        return q.empty();
    }
};