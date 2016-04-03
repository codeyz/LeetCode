/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        vector<TreeNode*> q;
        if(root->left)
            q.push_back(root->left);
        if(root->right)
            q.push_back(root->right);
        while(!q.empty())
        {
            if(q.size() % 2)
                return false;
            for(int i = 0, j = q.size() - 1; i <= j; ++i, --j)
            {
                if(q[i]->left && q[j]->right && q[i]->left->val != q[j]->right->val)
                    return false;
                if(q[i]->right && q[j]->left && q[i]->right->val != q[j]->left->val)
                    return false;
                if((q[i]->left && !q[j]->right) || (!q[i]->left && q[j]->right))
                    return false;
                if(q[i]->val != q[j]->val)
                    return false;
            }
            vector<TreeNode*> tmp;
            for(size_t i = 0;i < q.size(); ++i)
            {
                if(q[i]->left)
                    tmp.push_back(q[i]->left);
                if(q[i]->right)
                    tmp.push_back(q[i]->right);
            }
            q = tmp;
        }
        return true;
    }
};
*/

// recursion
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if((!left && !right))
            return true;
        if((left && !right) || (!left && right) || (left && right && left->val != right->val))
            return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};


