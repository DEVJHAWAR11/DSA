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
class compare{
public:
    bool operator()(ListNode*a,ListNode*b){
        return a->val > b->val;
    }  
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,vector<ListNode*>,compare>pq;

        //first elements
        for(int i=0;i<lists.size();i++){
            ListNode* topNode=lists[i];
            if(topNode) pq.push(topNode);
        }

        ListNode*head=NULL;
        ListNode* tail=NULL;

        while(!pq.empty()){
            ListNode* topNode=pq.top();
            pq.pop();

            if(!head){          //if ans ll empty then 
                head=topNode;
                tail=topNode;
                if(topNode->next)            //if a node exist then push
                    pq.push(topNode->next);
            }
            else{
                tail->next=topNode;
                tail=topNode;
                if(topNode->next)
                    pq.push(topNode->next);
            }
        }
        return head;
    }
};