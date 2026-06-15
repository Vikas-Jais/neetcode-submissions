class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto row : board) {
            unordered_set<char> st;
            for (auto box : row) {
                if (box == '.') continue;
                if (st.count(box))
                    return false;
                st.insert(box);
            }
        }
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (st.count(board[j][i]))
                    return false;
                st.insert(board[j][i]);
            }
        }
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                unordered_set<char> st;
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        if (board[i][j] == '.') continue;
                        if (st.count(board[i][j]))
                            return false;
                        st.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};