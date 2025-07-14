/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        // if(!head) return 0;
        // if(!head->next && head->val ==0) return 0;
        // if(!head->next && head->val ==1) return 1;
        // vector<int>temp;
        // ListNode*ptr=head;
        // while(ptr!=NULL){
        //     temp.push_back(ptr->val);
        //     ptr=ptr->next;
        // }
        // int ans=0;
        // for(int i=0;i<temp.size();i++){
        //     ans+=temp[temp.size()-i-1]*pow(2,i);
        // }
        // return ans;

        int res = 0;
        while(head!=NULL){
            res = (res << 1) + head->val;
            head = head->next;
        }
        return res;

    }
};