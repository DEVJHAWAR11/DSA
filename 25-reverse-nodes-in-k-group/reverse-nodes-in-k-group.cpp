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
    ListNode* findKNode(ListNode*temp,int k){
        while(temp && k>1){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    void reverse(ListNode* &temp){
        ListNode*prev=NULL,*curr=temp;
        while(curr!=NULL){
            ListNode*newNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newNode;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head,*prevNode=NULL;
        if(head==NULL) return head;
        while(temp){
            ListNode*kNode=findKNode(temp,k);
            if(kNode==NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            ListNode*nextNode=kNode->next;
            kNode->next=NULL;
            //reverse
            reverse(temp);
            if(head==temp){
                head=kNode;
            }
            else{
                prevNode->next=kNode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};