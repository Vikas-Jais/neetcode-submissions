class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevs(heights.size(),-1);
        vector<int> nexts(heights.size(),heights.size());
        stack<int> st;
        int max_area=-1;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                nexts[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[i]<heights[st.top()]){
                prevs[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<heights.size();i++){
            int width=nexts[i]-prevs[i]-1;
            int area=heights[i]*width;
            max_area=max(max_area,area);
        }
        return max_area;
    }
    
};
