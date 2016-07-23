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
    int minDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        if(root->left && !root->right)
            return minDepth(root->left) + 1;
        if(!root->left && root->right)
            return minDepth(root->right) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

*/

// non-recursion
class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        int depth = 0;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            ++depth;
            size_t num = q.size();
            for(size_t i = 0;i < num; ++i)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(!tmp->left && !tmp->right)
                    return depth;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
        return depth;
    }
};

