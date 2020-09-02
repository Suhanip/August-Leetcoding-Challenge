/*PROBLEM STATEMENT:

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
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
    //Including the root value
     int pathSum_a(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
        int count = 0;
        if(root->val == sum)
            count++;
        count = count+pathSum_a(root->left,sum-root->val);
        count = count+pathSum_a(root->right,sum-root->val);
        return count;
    }
public:
    //Includes both the cases of including or not including the root
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
        return pathSum(root->left,sum) + pathSum_a(root,sum) + pathSum(root->right,sum);
    }
};
