/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return head;
        Node* temp=head;
        while(temp){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        Node* curr=head->next;
        Node* prev=head;
        while(true){
            if(prev->random==nullptr){
                curr->random=nullptr;
            }
            else{
                curr->random=prev->random->next;
            }
            if(curr->next==nullptr)break;
            prev=prev->next->next;
            curr=curr->next->next;
        }
        Node* res=head->next;
        curr=head->next;
        prev=head;
        while(curr->next){
            Node* temp=curr->next;
            curr->next=curr->next->next;
            prev->next=temp;
            curr=curr->next;
            prev=temp;
        }
        prev->next=nullptr;
        curr->next=nullptr;
        return res;
    }
};
