class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        while (!st.empty()) {
            int num = *st.begin();
            st.erase(num);

            int length = 1;

            int left = num - 1;
            while (st.count(left)) {
                st.erase(left);
                length++;
                left--;
            }

            int right = num + 1;
            while (st.count(right)) {
                st.erase(right);
                length++;
                right++;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};