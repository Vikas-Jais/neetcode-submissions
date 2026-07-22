class Solution {
public:
    vector<vector<int>> adj;
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1){
            return false;
        }
        adj.resize(n);
        vector<bool> vis(n,false);

        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        if(!dfs(0,-1,vis))return false;

        for(bool it:vis){
            if(!it)return false;
        }
        return true;
    }

    bool dfs(int i,int p,vector<bool>& vis){
        vis[i]=true;
        for(auto it:adj[i]){
            if(it==p)continue;
            if(vis[it]){
                return false;
            }
            if(!dfs(it,i,vis)){
                return false;
            }
        }
        return true;
    }
};
