class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> results;
        stack<int> inStack;
        for (int i : nums2){
            while (!inStack.empty() && i > inStack.top()){
                results[inStack.top()] = i;
                inStack.pop();
            }
            inStack.push(i);
        }
        vector<int> answers;
        answers.reserve(nums1.size());

        for (int i: nums1){
            auto it = results.find(i);
            if (it == results.end()){
                answers.push_back(-1);
            }
            else {
                answers.push_back(results[i]);
            }
        }
        return answers;
        
    }
};
