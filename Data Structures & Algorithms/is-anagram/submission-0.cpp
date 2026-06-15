class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mp_s;
        unordered_map<int,int> mp_t;
        for (char it:s){
            mp_s[it]++;
        }

        for(char it:t){
            mp_t[it]++;
        }

        if(mp_s==mp_t){
            return true;
        }
        return false;
    }
};
