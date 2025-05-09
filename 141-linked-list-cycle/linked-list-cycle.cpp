/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>mpp;

        ListNode* temp=head;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()){
                return true;
            }
            else{
                mpp[temp]=true;
            }
            temp=temp->next;
        }
        return false;
    }
};