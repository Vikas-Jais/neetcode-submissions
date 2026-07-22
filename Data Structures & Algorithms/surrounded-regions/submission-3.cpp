class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                board[i][0]='T';
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                board[i][m-1]='T';
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                board[0][i]='T';
                q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                board[n-1][i]='T';
                q.push({n-1,i});
            }
        }

        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int i =q.front().first;
            int j =q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int r=i+dir[k][0];
                int c=j+dir[k][1];

                if(r<0 || r>=n || c>=m || c<0 || board[r][c]!='O'){
                    continue;
                }
                board[r][c]='T';
                q.push({r,c});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='T'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
