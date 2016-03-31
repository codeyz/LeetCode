/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/* recursion
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
*/

//non-recusion
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        int depth = 0;
        queue<TreeNode*> queueOfNode;
        if(root)
        {
            queueOfNode.push(root);
        }
        while(!queueOfNode.empty())
        {
            ++depth;
            //pop all nodes at the same level, and push all nodes at the next level
            size_t num = queueOfNode.size();
            for(size_t i = 0;i < num; ++i)
            {
                TreeNode* tmp = queueOfNode.front();
                queueOfNode.pop();
                if(tmp->left)
                    queueOfNode.push(tmp->left);
                if(tmp->right)
                    queueOfNode.push(tmp->right);
            }
        }
        return depth;
    }
};
