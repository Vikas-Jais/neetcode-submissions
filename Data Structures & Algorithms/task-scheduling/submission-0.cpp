class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>>  pq;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) q.push({-1,-1});
        vector<int> freq(26,0);
        for(int it:tasks) freq[it-'A']++;
        
        for(int i=0;i<26;i++) {
            if(freq[i]!=0) pq.push({freq[i],i});
        }
        int count=tasks.size();
        int cycles=0;
        while(count){
            pair<int,int> tpq={-1,-1};
            pair<int,int> tq;
            if(!pq.empty()){ tpq=pq.top(); tpq.first--; pq.pop(); count--;}
            tq=q.front();
            q.pop();
            cycles++;
            if(tpq.first>0) q.push(tpq);
            else q.push({-1,-1});
            if (tq.first!=-1)
            pq.push(tq);
        }
        return cycles;
    }
};
