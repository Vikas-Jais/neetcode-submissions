class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int it:nums){
            if(mp.count(it)){
                return true;
            }
            mp[it]++;
        }

        return false;
    }
};