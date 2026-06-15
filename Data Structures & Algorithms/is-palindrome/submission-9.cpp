class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        while(l<r){
            while(l<r && !IsValid(s[l]))l++;
            while(l<r && !IsValid(s[r]))r--;
            if(tolower(s[l])!= tolower(s[r])){return false;}
            l++;
            r--;
        }
        return true;
    }

    bool IsValid(char ch){
        if(ch>='A'&& ch<='Z'||ch>='a'&& ch<='z' ||ch>='0'&&ch<='9') return true;
        else return false;
    }
};
