#include <vector>
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
    int sum;
    void sumPaths(TreeNode* node, int s) {
        if(node == nullptr)
            return;
        if(node->right == nullptr && node->left == nullptr) {
            sum += s * 10 + node->val;
        }
        sumPaths(node->left, s * 10 + node->val);
        sumPaths(node->right, s * 10 + node->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        sumPaths(root, 0);
        return sum;
    }
};
