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

 //approach1
// class Solution {
// public:
//     bool isCompleteTree(TreeNode* root) {
//         //ek null ke baad ek notnull nhi aana chahiye agar aaya toh not complete
//         //toh keep adding in queue jab tak pehla null nhi mil jaata
//         //after that keep popping all null from queue
//         //if at last we get a empty queue -->then complete else not
//         queue<TreeNode*>q;
//         q.push(root);
//         while(q.front()){
//             TreeNode* node=q.front();
//             q.pop();
//             q.push(node->left);
//             q.push(node->right);
//         }
//         while(!q.empty()&& !q.front()){
//             q.pop();
//         }
//         return q.empty();
//     }
// };


//aproach 2
//if we get null then we mark a flag variable and then if we get a not null then and if flag is marked then return false  
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool flag=false;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL) flag=true;
            else{    //jab not null aaye
                if(flag) return false;   //flag tab hi true hoga agar ek null a gya hoga

                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};