class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it: tokens){
            if(isdigit(it[0]) || (it.size()>1 && it[0]=='-')){
                st.push(stoi(it));
            }
            else{
                int val1=st.top(); st.pop();
                int val2=st.top(); st.pop();
                int res=0;
                if(it=="+")res=val1+val2;
                else if(it=="-")res=val2-val1;
                else if(it=="*")res=val1*val2;
                else if(it=="/"){res=val2/val1;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};
