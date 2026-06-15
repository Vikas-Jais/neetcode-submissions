class Solution {
public:
    int trap(vector<int>& heights) {
        int l=1;
        int r=heights.size()-2;
        int lmax=heights[0];
        int rmax=heights[r+1];
        int water=0;
        while (l <= r) {
            if (lmax <= rmax) {
                water += max(0, lmax - heights[l]);
                lmax = max(lmax, heights[l]);
                l++;
            } else {
                water += max(0, rmax - heights[r]);
                rmax = max(rmax, heights[r]);
                r--;
            }
        }
        return water;
    }
};
