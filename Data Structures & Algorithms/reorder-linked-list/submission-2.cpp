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
    void reorderList(ListNode* head) {

        //finding middle element 
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        //split in two linked list and reverse second one
        ListNode* prev=nullptr;
        ListNode* temp=slow;
        slow=slow->next;
        temp->next=nullptr;
        
        while(slow!=nullptr){
            ListNode* temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        
        //merge two linked list
        slow=head;
        while(prev){
            ListNode* temp1=slow->next;
            ListNode* temp2=prev->next;
            slow->next=prev;
            prev->next=temp1;
            slow=temp1;
            prev=temp2;
        }
    }
};
