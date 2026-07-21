class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int size=q.size();
        int time=0;
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int i =q.front().first;
            int j =q.front().second;
            q.pop();
            size--;

            for(int k=0;k<4;k++){
                int r=i+dir[k][0];
                int c=j+dir[k][1];

                if(r<0 || r>=n || c>=m || c<0 || grid[r][c]==0 || grid[r][c]==2){
                    continue;
                }
                grid[r][c]=2;
                q.push({r,c});
            }
            if(size==0){
                if(!q.empty())time++;
                size=q.size();
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};
