class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0]=1;
        res[nums.size()-1]=1;

        for(int i=1;i<nums.size();i++){
            res[i]=res[i-1]*nums[i-1];
        }
        int suffix=1;
        for(int i=res.size()-1;i>=0;i--){
            res[i]=res[i]*suffix;
            suffix*=nums[i];            
        }
        return res;
    }
};
