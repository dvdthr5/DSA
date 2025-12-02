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

    bool testForEquality(TreeNode* root, TreeNode* subRoot){
        if (subRoot == NULL && root == NULL){
            return true;
        }
        if (root == NULL || subRoot == NULL){
            return false;
        }

        bool rootsMatch = (root->val == subRoot->val);
        if (!rootsMatch){
            return false;
        }
        bool leftChildEqual = testForEquality(root->left, subRoot->left);
        bool rightChildEqual = testForEquality(root->right, subRoot->right);
        return (leftChildEqual && rightChildEqual);
    }

    TreeNode* findRootNode(TreeNode* root, TreeNode* subRoot){
        if (root == NULL){
            return NULL;
        }
        if (subRoot->val == root->val){
             if (testForEquality(root, subRoot)){
                return root;
             }
        }
            TreeNode* leftChild = findRootNode(root->left, subRoot);
            TreeNode* rightChild = findRootNode(root->right, subRoot);
            if (leftChild == NULL && rightChild == NULL){
                return NULL;
            }
            if (leftChild != NULL){
                return leftChild;
            }
            if (rightChild != NULL){
                return rightChild;
            } 
        return NULL;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (findRootNode(root, subRoot) != NULL){
            return true;
        }
        return false;
    }
};
