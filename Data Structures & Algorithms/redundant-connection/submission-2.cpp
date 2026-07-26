class Solution {
public:
    unordered_map<int,vector<int>> mp;
    int cycle=0;
    vector<int> cyc;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<bool> vis(n+1,false);
        unordered_set<int> st;

        for(auto it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        if(!dfs(1,-1,vis)){
            int i=0;
            while(cyc[i]!=cycle){
                i++;
            }
            int k=cyc.size();
            while(i!=k){
                st.insert(cyc[i]);
                i++;
            }
        }
        int j=n-1;
        while(j!=0){
            int u=edges[j][0];
            int v=edges[j][1];
            if(st.count(u) && st.count(v)){
                return {u,v};
            }
            j--;
        }
        return {};
    }

    bool dfs(int i,int p,vector<bool>& vis){
        vis[i]=true;
        cyc.push_back(i);
        for(auto it:mp[i]){
            if(it==p)continue;
            if(vis[it]==true){
                cycle=it;
                return false;
            }
            if(!dfs(it,i,vis)){
                return false;
            }
        }
        cyc.pop_back();
        return true;
    }
};
