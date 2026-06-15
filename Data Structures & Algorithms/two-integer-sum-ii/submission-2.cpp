class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while(l<r){
            int ans =numbers[l]+numbers[r];
            if(ans==target){
                return{l+1,r+1};
            }
            if(ans<target){
                l++;
            }
            if(ans>target){
                r--;
            }
        }
        return {};
    }
};
