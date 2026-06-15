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
        prev=head;
        curr=res;

        while(prev && curr){
            prev->next=curr->next;
            prev=prev->next;

            if(prev){
            curr->next=prev->next;
            curr=curr->next;
            }
        }   
        return res;
    }
};
