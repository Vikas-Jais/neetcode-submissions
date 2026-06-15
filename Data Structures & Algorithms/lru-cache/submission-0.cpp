class Node{
public:
    int data;
    int key;
    Node* next;
    Node* prev;
    Node(int key,int data){
        this->next=nullptr;
        this->prev=nullptr;
        this->data=data;
        this->key=key;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void remove(Node* ntr){
        ntr->prev->next=ntr->next;
        ntr->next->prev=ntr->prev;
    }

    void insert(Node* nti){
        nti->prev=tail->prev;
        nti->prev->next=nti;
        nti->next=tail;
        tail->prev=nti;
    }
    
    int get(int key) {
        if(mp.count(key)){
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->data; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->data=value;
            remove(mp[key]);
            insert(mp[key]);
            return;
        }
        if(mp.size()<capacity){
            Node* node=new Node(key,value);
            insert(node);
            mp[key]=node;
        }
        else{
            mp.erase(head->next->key);
            head->next->key=key;
            head->next->data=value;
            mp[key]=head->next;
            remove(mp[key]);
            insert(mp[key]);
        }
        return;
    }
};
