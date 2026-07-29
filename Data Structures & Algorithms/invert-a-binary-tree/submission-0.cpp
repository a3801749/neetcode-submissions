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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) { return root; }

        deque<TreeNode*> node_queue;
        node_queue.push_back(root);

        while (!node_queue.empty()) {
            TreeNode* front = node_queue.front();

            TreeNode* right = front->right;
            TreeNode* left = front->left;

            if (right) {
                node_queue.push_back(right);
            }
            if (left) {
                node_queue.push_back(left);
            }

            front->left = right;
            front->right = left;

            node_queue.pop_front();
        }

        return root;
    }
};
