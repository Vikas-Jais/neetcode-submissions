class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int high=piles[n-1];
        int low=1;
        int k=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int sum=0;
            for(auto it: piles){
                sum+=(it+mid-1)/mid;
            }
            if(sum>h){
                low=mid+1;
            }
            else{
                k=min(k,mid);
                high=mid-1;
            }
        }
        return k;
    }
};
