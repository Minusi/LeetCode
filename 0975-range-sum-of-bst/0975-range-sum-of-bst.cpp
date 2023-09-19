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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
        {
            return 0;
        }

        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.empty() == false)
        {
            auto node = q.front();
            q.pop();
            
            if (low <= node->val && node->val <= high)
            {
                sum += node->val;
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            else if (node->val < low)
            {
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            else if (node->val > high)
            {
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
            }
        }

        return sum;
    }
};