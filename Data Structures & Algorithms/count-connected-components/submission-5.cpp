class Solution {
public:
    vector<vector<int>> adj;
    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        adj.resize(n);
        vector<bool> vis(n,false);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis);
                count++;
            }
        }
        return count;
    }

    void dfs(int i,vector<bool>& vis){
        vis[i]=true;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,vis);
            }
        }
    }
};
