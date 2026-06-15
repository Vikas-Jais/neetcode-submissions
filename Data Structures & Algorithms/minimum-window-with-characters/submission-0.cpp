class Solution{
public:
    string minWindow(string s,string t){
        unordered_map<char,int> st;
        for(auto it:t){
            st[it]++;
        }
        unordered_map<char,int> cst;
        int required=st.size();
        int formed=0;
        int r=0;
        int minlength=INT_MAX;
        vector<int> res(2,-1);
        for(int i=0;i<s.length();i++){
            while(r<s.length()&&formed<required){
                cst[s[r]]++;
                if(st.count(s[r])&&cst[s[r]]==st[s[r]]){
                    formed++;
                }
                r++;
            }
            if(formed==required){
                if(r-i<minlength){
                    minlength=r-i;
                    res[0]=i;
                    res[1]=r;
                }
            }
            cst[s[i]]--;
            if(st.count(s[i])&&cst[s[i]]<st[s[i]]){
                formed--;
            }
        }
        if(res[0]==-1)return "";
        return s.substr(res[0],res[1]-res[0]);
    }
};
