class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        for (char c : t) {
            need[c]++;
        }
        int left = 0, right = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            char c = s[right];
            if (need[c] > 0) {
                count--;
            }
            need[c]--;
            right++;

            while (count == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                char ch = s[left];
                need[ch]++;
                if (need[ch] > 0) {
                    count++;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};