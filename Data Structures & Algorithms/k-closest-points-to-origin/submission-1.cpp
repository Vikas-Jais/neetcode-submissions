class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>> pq;
        int i=0;
        for(auto it: points){
            pq.push({sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]),i});
            if(pq.size()>k)pq.pop();
            i++;
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;        
    }
};
