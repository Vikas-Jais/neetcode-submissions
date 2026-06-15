class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<vector<int>> res(nums.size()+1);
        for(auto it: mp){
            res[it.second].push_back(it.first);
        }

        int n= res.size();
        vector<int> ans;
        int count=0;
        for(int i=n-1;i>0 && ans.size()<k;i--){
            for(const auto& it:res[i]){
                ans.push_back(it);
                if(ans.size()==k)return ans;
            }
        }
        return ans;

    }
};