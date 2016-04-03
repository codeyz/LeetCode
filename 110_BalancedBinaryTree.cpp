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
    bool isBalanced(TreeNode* root) 
    {
        if(!root)
            return true;
        if(abs(getHeight(root->left) - getHeight(root->right)) > 1) // not balanced
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};
*/

// non-recursion
class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        stack<TreeNode*> s;
        pushNodeAndAllChildren(s, root);
        while(!s.empty())
        {
            TreeNode* tmp = s.top();
            s.pop();
            if(abs(getHeight(tmp->left) - getHeight(tmp->right)) > 1) // not balanced
                return false;
            pushNodeAndAllChildren(s, tmp->right);
        }
        return true;
    }
    
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxHeight = 0;
        while(!q.empty())
        {
            ++maxHeight;
            size_t numOfNodes = q.size();
            for(size_t i = 0;i < numOfNodes; ++i)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
        return maxHeight;
    }
    
    void pushNodeAndAllChildren(stack<TreeNode*>& s, TreeNode* root)
    {
        if(!root)
            return;
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }
};
