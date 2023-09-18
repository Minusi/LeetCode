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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            return nullptr;
        }

        TreeNode* nodeToFind = root;
        while (nodeToFind != nullptr)
        {
            if (val > nodeToFind->val)
            {
                nodeToFind = nodeToFind->right;
            }
            else if (val < nodeToFind->val)
            {
                nodeToFind = nodeToFind->left;
            }
            else
            {
                return nodeToFind;
            }
        }

        return nullptr;
    }
};