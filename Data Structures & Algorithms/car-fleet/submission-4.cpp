class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> ps;
        stack<double> st;
        for(int i=0;i<position.size();i++){
            ps.push_back({position[i],speed[i]});
        }
        sort(ps.begin(),ps.end());
        int count=0;
        for(int i=ps.size()-1;i>=0;i--){
            double time= double(target-ps[i].first)/ps[i].second;
            if(!st.empty() && time<=st.top()){
                continue;
            }
            st.push(time);
            count++;
        }
        return count;
    }
};
