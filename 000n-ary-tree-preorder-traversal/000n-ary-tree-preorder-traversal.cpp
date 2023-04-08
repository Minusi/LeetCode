/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        std::vector<int> result;
        std::list<Node*> nodeStack;
        if(root == nullptr)
        {
            return result;
        }


        nodeStack.push_back(root);
        while(nodeStack.empty() == false)
        {
            auto node = nodeStack.back();
            nodeStack.pop_back();

            result.push_back(node->val);
            for(auto rit = node->children.rbegin(); rit != node->children.rend(); ++rit)
            {
                nodeStack.push_back(*rit);
            }
        }

        return result;
    }
};