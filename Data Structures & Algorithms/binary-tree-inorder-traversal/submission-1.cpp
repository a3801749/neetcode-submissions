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

        TreeNode* leftmost = root;
        deque<TreeNode*> process_left;

        while (leftmost -> left != nullptr) {
            process_left.push_back(leftmost);
            leftmost = leftmost->left;
        }

        process_left.push_back(leftmost);

        while (!process_left.empty()) {
            TreeNode* current = process_left.back();
            process_left.pop_back();
            if (current->right) {
                process_left.push_back(current->right);
                TreeNode* leftmost_of_right = current->right->left;
                while (leftmost_of_right) {
                    process_left.push_back(leftmost_of_right);
                    leftmost_of_right = leftmost_of_right->left;
                }
            }
            result.push_back(current->val);
        }

        return result;

    }
};