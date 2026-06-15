class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for(char c : s1)
            cnt1[c - 'a']++;

        int k = s1.size();

        for(int i = 0; i < s2.size(); i++) {
            cnt2[s2[i] - 'a']++;

            if(i >= k)
                cnt2[s2[i - k] - 'a']--;

            if(cnt1 == cnt2)
                return true;
        }

        return false;
    }
};