class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> current;
        combinationSumRec(candidates, target, 0, current, results);
        return results;
    }

    int sum(vector<int>& candidates){
        int vecSize = candidates.size();
        int sum = 0;
        for (int i = 0; i < vecSize; i++){
            sum += candidates[i];
            }
        return sum;
    }

    void combinationSumRec(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& results){
        if (sum(current) == target){
            results.push_back(current);
            return;
        }
        if (sum(current) > target){
            return;
        }
        int vecSize = candidates.size();
        for (int i = start; i < vecSize; i++) {
            current.push_back(candidates[i]);
            combinationSumRec(candidates, target, i, current, results);
            current.pop_back();
        }
    }



};
