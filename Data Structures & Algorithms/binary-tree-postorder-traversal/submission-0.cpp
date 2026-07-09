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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) { return result; }

        deque<TreeNode*> pre_help;
        TreeNode* current = root;
        pre_help.push_back(root);

        while (!pre_help.empty()) {
            current = pre_help.back();
            pre_help.pop_back();

            if (current->left) {
                pre_help.push_back(current->left);
            }

            if (current->right) {
                pre_help.push_back(current->right);
            }

            result.push_back(current->val);
        }
        std::reverse(result.begin(), result.end());

        return result;  
    }
};