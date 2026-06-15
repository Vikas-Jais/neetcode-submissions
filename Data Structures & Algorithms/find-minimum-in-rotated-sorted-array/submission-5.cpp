class Solution {
public:
    int findMin(vector<int> &nums) {
        int low=0;
        int high=nums.size()-1;
        int min_ele=nums[0];

        while(low<=high){
            int m=low+(high-low)/2;
            
            if(nums[m]<nums[low]){
                min_ele=min(min_ele,nums[m]);
                high=m-1;
            }

            else if(nums[high]<nums[low]){
                min_ele=min(min_ele,nums[m]);
                low=m+1;
            }

            else{
                min_ele=min(min_ele,nums[low]);
                return min_ele;
            }
        }
        return min_ele;

    }
};
