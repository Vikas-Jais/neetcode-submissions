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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp_h =head;
        ListNode* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        count=count/k;
        if(count>=1){
            int i=1;
            temp=head;
            while(i!=k){
                i++;
                temp=temp->next;
            }
        }
        ListNode* prev_t=nullptr;
        for(int i=0;i<count;i++){
            ListNode* curr=temp_h;
            ListNode* prev=nullptr;
            int n=0;
            while(n!=k){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
                n++;
            }
            if(prev_t!=nullptr){
                prev_t->next=prev;
            }
            prev_t=temp_h;
            temp_h=curr;
        }
        prev_t->next=temp_h;
        return temp;
    }
};
