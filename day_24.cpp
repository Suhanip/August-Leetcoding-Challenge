/*PROBLEM STATEMENT:
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

*/

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
    int sum = 0;
    void sumOfLeftLeaves(TreeNode* root, bool isLeft){
        if(isLeft && !root->left && !root->right){
            sum += root->val;
            return;
        }
        if(root->left) sumOfLeftLeaves(root->left, true);
        if(root->right) sumOfLeftLeaves(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        sumOfLeftLeaves(root, false);
        return sum;
    }
};
