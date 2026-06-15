class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int count=0;
        unordered_set<char> st;
        while(r<s.length()){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            count= max(count,(int)st.size());
            r++;
        }
        return count;
    }
};
