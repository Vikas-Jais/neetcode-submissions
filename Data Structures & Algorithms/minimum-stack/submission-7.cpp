class MinStack {
public:
    long long min_ele=-1;
    stack<long> st;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            min_ele=val;
        }
        else if(val>min_ele){
            st.push(val);
        }
        else{
            long long encoded= 2LL*val-min_ele;
            st.push(encoded);
            min_ele=val;
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long top=st.top();
        st.pop();

        if(top<min_ele){
            min_ele=2LL*min_ele-top;
        }
    }
    
    int top() {
        if(st.empty())return -1;
        if(st.top()<min_ele){
            return min_ele;
        }
        else{
            return st.top();
        }
    }
    
    int getMin() {
        if(st.empty())return -1;
        return min_ele;
    }
};
