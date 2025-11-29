class Solution {
public:
    bool isValid(string s) {
        int paren = 0;
        int brace = 0;
        int brack = 0;
        std::vector<char> left;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '{'){
                brace++;
                left.push_back(s[i]);
            }
            else if (s[i] == '('){
                paren++;
                left.push_back(s[i]);
            }
            else if (s[i] == '['){
                brack++;
                left.push_back(s[i]);
            }
            else if (s[i] == '}'){
                brace--;
                if (left.size() == 0 ||left.back() != '{'){
                    return false;
                }
                else{
                    left.pop_back();
                }
            }
            else if (s[i] == ']'){
                brack--;
                if (left.size() == 0 || left.back() != '['){
                    return false;
                }
                else{
                    left.pop_back();
                }
            }
            else if (s[i] == ')'){
                paren--;
                if (left.size() == 0 || left.back() != '('){
                    return false;
                }
                else{
                    left.pop_back();
                }
            }
            else {
                return false;
            }
            if (paren < 0 || brace < 0 || brack < 0){
                return false;
            }
        }
        if (paren != 0 || brace != 0 || brack != 0){
            return false;
        }
        return true;
    }
};
