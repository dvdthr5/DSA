class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for (int i = 1 ; i <= numRows; i++){
            vector<int> current;
            for (int j = 1; j <= i; j++){
                if (j == 1 || j == i){
                    current.push_back(1);
                }
                else{
                    int val = answer[i - 2][j-2] + answer[i-2][j-1];
                    current.push_back(val);
                }
            }
            answer.push_back(current);
        }
        return answer;
    }
};
