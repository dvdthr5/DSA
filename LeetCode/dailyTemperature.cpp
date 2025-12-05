class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int m = temperatures.size();
        vector<int> answers(m, 0);
        int counter = 0;
        for (int i =0; i < m; i++){
            while (!st.empty() && temperatures[i] > temperatures[st.top()]){
                answers[st.top()] = i - st.top(); 
                st.pop();
            }
            st.push(i);
        }

        return answers;
    }
};
