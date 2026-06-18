class Solution {
public:
    bool isValid(string s) {
        int top=-1;
        for(int i=0;i<s.length();i++){
            int c= s[i];
            if(c=='[' || c=='{' || c=='('){
                s[++top]=s[i];
            }
            if(top==-1)return false;
            if(c==']' || c=='}' || c==')'){
                if(c==']' && s[top]!='[' 
                    || c=='}' && s[top]!='{' 
                    || c==')' && s[top]!='(')return false;
                top--;
            }            
        }
        return top==-1;
    }
};
