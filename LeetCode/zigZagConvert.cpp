class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2){
            return s;
        }
        int sizeV = s.length();
        int n = 2*numRows - 2;
        int cycles = sizeV / n;
        int divc = (numRows-1)*(cycles+1);
        int current = 0;
        int row = 0;
        int column = 0;
        bool goingUp = false;
        vector<vector<char>> blank(numRows, vector<char>(divc, '0'));
        while (current < sizeV){
            if (column % (numRows-1) == 0){
                blank[row][column] = s[current];
                current++;
                row++;
                if (row >= numRows){
                    row--;
                    goingUp = true;
                }
            }
            while (goingUp){
                if (row == 1){
                    row = 0;
                    goingUp = false;
                    column++;
                    break;
                }
                row--;
                column++;
                if (current >= sizeV) break;
                blank[row][column] = s[current];
                current++;
            }
        }
        string result = "";
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < divc; j++){
                if (blank[i][j] != '0'){
                    result.push_back(blank[i][j]);
                }
            }
        }
        return result;
    }
};
