# Patterns of Algoritms:

## Monotonic Stacks

### Use Cases

Monotonic stacks are most useful for problems that ask for

- The next greatr or next smaller elemeent
- The previous greater or previous smaller element
- The nearest element that satisfies some ordering constraint
- Efficiently processing elements that need to maintain a relationship with later elements

Monotonic stacks maintain elements in sorted order (increasing or decreasing) as you iterate through the list. It allows for solving next/previous x questions in O(n) time. 

### Why It Works

A monotonic stack differs from a stack in that it is always sorted. There are two types, monotonically decreasing stacks, where the top is always the smallest element in the stack, and monotonically increasing stacks, where the top is always the largest element in the stack. 

Whenever a value is introduced that would violate the sorted order, elements are popped from the top until the order is corrected. 

Classic examples of problmes that can be solved with monotonic stacks include Next Greater Element, Daily Temperature, Stock Span, and variations of the histogram rectangle problems. 

### Examples

Next Greater Element (LeetCode Variant)
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
Daily Temperatures
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
