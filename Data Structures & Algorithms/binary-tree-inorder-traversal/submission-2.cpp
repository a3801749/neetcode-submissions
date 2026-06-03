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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        deque<TreeNode*> process;

        while (root != nullptr || !process.empty()) {
            while (root != nullptr) {
                process.push_back(root);
                root = root->left;
            }
            root = process.back();
            process.pop_back();
            result.push_back(root->val);
            root = root->right;
        }       

        return result;

    }
};