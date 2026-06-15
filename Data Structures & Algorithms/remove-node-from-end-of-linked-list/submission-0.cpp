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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr)return head;
        ListNode* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        int k= count-n;
        temp=head;
        ListNode* prev=nullptr;
        int i=0;
        while(i!=k){
            prev=temp;
            temp=temp->next;
            i++;
        }
        if(temp==head){
            ListNode* res=temp->next;
            delete temp;
            return res;
        }
        else{
            prev->next=temp->next;
            delete temp;
            return head;
        }
    }
};
