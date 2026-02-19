class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> answer;
        int n = digits.size();
        bool carry = false;
        bool firstNum = true;
        for (int i = n - 1; i >= 0; i--){
            if (carry == true){
                digits[i]++;
                carry = false;
            }
            if (firstNum){
                firstNum = false;
                digits[i]++;
            }
            if (digits[i] >= 10){
                carry = true;
                digits[i] -= 10;
            }
            answer.push_back(digits[i]);
        }
        if (carry == true){
            answer.push_back(1);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
