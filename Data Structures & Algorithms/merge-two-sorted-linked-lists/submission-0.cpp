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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* i1= list1;
        ListNode* i2= list2;
        ListNode* head=nullptr;
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        if(i1->val<=i2->val){
            head=i1;
            i1=i1->next;
        }
        else{
            head=i2;
            i2=i2->next;
        }
        ListNode* temp=head;
        while(i1!=nullptr && i2!=nullptr){
            if(i1->val<=i2->val){
                temp->next=i1;
                temp=temp->next;
                i1=i1->next;
            }
            else{
                temp->next=i2;
                temp=temp->next;
                i2=i2->next;
            } 
        }
        if(i1!=nullptr){
            temp->next=i1;
        }
        if(i2!=nullptr){
            temp->next=i2;
        }
        return head;
    }
};
