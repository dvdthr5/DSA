class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const char* start = s.c_str();
        const char* end = s.c_str();
        const char *strEnd = start + s.size();
        int currentMax = 0;

        while (end < strEnd){
        const char* jumper = start;
            while (jumper < end && *jumper != *end ){
                jumper ++;
            }
            if (jumper < end){
                start = jumper + 1;
            }   
            int length = end - start + 1;
            if (length > currentMax){
                currentMax = length;
            }
            end++;
        }   
        return currentMax;
    }
};
