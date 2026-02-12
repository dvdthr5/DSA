/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void binaryTreePaths(TreeNode* root, string current, vector<string>& weGot){
        if (root == NULL){
            return;
        }
        current += to_string(root->val);
        
        if (root->left == NULL && root->right == NULL){
            weGot.push_back(current);
            return;
        }
        current.push_back('-');
        current.push_back('>');
        binaryTreePaths(root->right, current, weGot);
        binaryTreePaths(root->left, current, weGot);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> weGot;
        string empty;
        binaryTreePaths(root, empty, weGot);
        return weGot;
    }


};
