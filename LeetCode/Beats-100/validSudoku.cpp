class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>> rowTable(9, vector<bool>(10, false));
        vector<vector<bool>> colTable(9, vector<bool>(10, false));
        vector<vector<bool>> boxTable(9, vector<bool>(10, false));

        for (int r = 0 ; r < 9; r++){
            for (int c = 0 ; c < 9; c++){
                if (board[r][c] != '.'){
                    int boxNum = (r / 3) * 3 + (c / 3);
                    int digit = board[r][c] - '0';
                    if (rowTable[r][digit] || colTable[c][digit] || boxTable[boxNum][digit]){
                        return false;
                    }
                    rowTable[r][digit] = true;
                    colTable[c][digit] = true;
                    boxTable[boxNum][digit] = true;
                }
            }
        }
        return true;
    }
};
