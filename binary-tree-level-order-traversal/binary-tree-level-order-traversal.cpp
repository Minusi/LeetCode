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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if(root == nullptr)
        {
            return result;
        }

        std::list<TreeNode*> nodeList;
        nodeList.push_back(root);

        size_t currentIndex = 1;
        size_t nextIndex = 0;

        std::vector<int> level;
        while(nodeList.empty() == false)
        {
            auto node = nodeList.front();
            nodeList.pop_front();

            level.push_back(node->val);
            if(node->left)
            {
                nodeList.push_back(node->left);
                ++nextIndex;
            }
            if(node->right)
            {
                nodeList.push_back(node->right);
                ++nextIndex;
            }

            --currentIndex;
            if(currentIndex == 0)
            {
                currentIndex = nextIndex;
                nextIndex = 0;
                result.push_back(std::move(level));
            }
        }

        return result;
    }
};