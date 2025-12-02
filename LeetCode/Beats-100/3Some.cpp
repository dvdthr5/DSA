class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answers;
        for (int i = 0 ; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1; 

            while (left < right){

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0){
                    answers.push_back({nums[i] , nums[left], nums[right]});

                    int lv = nums[left];
                    int rv = nums[right]; 
                    while (left < right && nums[left] == lv){
                        left++;
                    }
                    while (left < right && nums[right] == rv){
                        right--;
                    }
                }
                else if (sum > 0){
                    right--;
                } else{
                    left++;
                }


            }

        }


    return answers;
    }
};
