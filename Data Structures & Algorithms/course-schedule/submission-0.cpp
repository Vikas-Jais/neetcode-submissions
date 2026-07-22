class Solution {
public:
    unordered_map<int,vector<int>> mp;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> visited(numCourses,false);

        for(auto it:prerequisites){
            mp[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(i,vis,visited))return false;
            }
        }
        return true;
    }

    bool dfs(int i,vector<bool>& vis,vector<bool>& visited){
        if(vis[i]==true)return false;
        vis[i]=true;
        visited[i]=true;

        for(auto it:mp[i]){
            if(!dfs(it,vis,visited)){
                return false;
            }
        }
        vis[i]=false;
        return true;
    }
};
