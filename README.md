# Patterns of Algoritms:

## Monotonic Stacks

Monotonic Stacks are useful when finding the next element for some relation. Stacks provide easy management, constant time read and writes, and reduced complexity. Using a stack allows you to track all elements following a certain relation while only allowing you to access the most recently added element. Classic problems that can be optimally solved using monotonic stacks include nextGreaterElement and dailyTemperatures.
nextGreatestElement(Leetcode I Variant)
```cpp
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
```
dailyTemperature:
```cpp
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
```

___



## Fast and Slow Pointers

Fast and slow pointers inolves using two pointers that traverse a graph at different speeds. This method is useful for finding cycles in graphs. Conceptually, if you have two runners moving at vastly different speeds, on a straight course, they will never meet. If you have the same runners on a circular track, they will pass each other every so often due to different rates. If our pointers pass each other that means there is a cycle. Usually we do this by having the fast pointer move two nodes at a time and the slow pointer only iterating one node at a time.

## Sliding Window

When finding a subarray of k length, we use a sliding window of length k to save ourselves overhead on repeating calculations, subtracting the first value and adding the new value each times, instead of recalculating the sum of all k values. 

## DFS

Depth First Search(DFS) is the graph exploration method that looks down one path completely until it either fails a condition or reaches the end without the desired outcome. The concept behind recursive DFS algorithms is to edit the inductive variable, recursively call the method, and then swap the element back. This is the basis behind permutations. 
