class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();

        vector<vector<int>> pac(n,vector<int>(m,0));
        vector<vector<int>> atl(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            dfs(i,0,pac,heights);
            dfs(i,m-1,atl,heights);
        }

        for(int i=0;i<m;i++){
            dfs(0,i,pac,heights);
            dfs(n-1,i,atl,heights);
        }

        vector<vector<int>> res;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]==1 && atl[i][j]==1){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }

    void dfs(int i, int j, vector<vector<int>>& sea, vector<vector<int>>& heights){
        int n= heights.size();
        int m= heights[0].size();
        sea[i][j] = 1;
        vector<vector<int>> dir= {{-1,0},{1,0},{0,-1},{0,1}};
        for(int k=0;k<4;k++){
            int r=i+dir[k][0];
            int c=j+dir[k][1];

            if(r<0 || r>=n || c<0 || c>=m || sea[r][c]==1 || heights[r][c]<heights[i][j]){
                continue;
            }
            dfs(r,c,sea,heights);
        }
    }
};
