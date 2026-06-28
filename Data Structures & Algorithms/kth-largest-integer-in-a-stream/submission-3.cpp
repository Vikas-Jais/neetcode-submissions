class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k_k=0;
    KthLargest(int k, vector<int>& nums){
        this->k_k=k;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k_k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k_k){
            pq.pop();
        }
        return pq.top();
    }
};
