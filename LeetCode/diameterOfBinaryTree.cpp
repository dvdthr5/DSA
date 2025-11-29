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

    int diameterRecurse(TreeNode* root, int &globalDiameter){
        if (root == NULL){
            return 0;
        }

        int rightDepth = diameterRecurse(root->right, globalDiameter);
        int leftDepth = diameterRecurse(root->left, globalDiameter);

        if ((rightDepth + leftDepth) > globalDiameter){
            globalDiameter = rightDepth + leftDepth;
        }
        int maxH = rightDepth;
        if (leftDepth > maxH){
            maxH = leftDepth;
        }
        return 1 + maxH;

    }



    int diameterOfBinaryTree(TreeNode* root) {
        int globalDiameter = 0;
        diameterRecurse(root, globalDiameter);
        return globalDiameter;
    }
};
