class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (auto num : st) {
            if (!st.count(num - 1)) { 
                int curr = num;
                int length = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};