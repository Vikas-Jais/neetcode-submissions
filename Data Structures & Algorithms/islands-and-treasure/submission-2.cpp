class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int r=i+dir[k][0];
                int c=j+dir[k][1];

                if(r<0 || r>=n || c<0 || c>=m || grid[r][c]!=INT_MAX){
                    continue;
                }
                grid[r][c]=grid[i][j]+1;
                q.push({r,c});
            }
        }
    }
};
