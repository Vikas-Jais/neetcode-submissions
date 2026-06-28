class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it: stones){
            pq.push(it);
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(y<x){
                pq.push(x-y);
            }
        }
        pq.push(0);
        return pq.top();
    }
};
