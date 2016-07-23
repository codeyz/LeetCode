/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int> > res;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            size_t num = q.size();
            vector<int> tmp;
            for(int i = 0;i < num; ++i)
            {
                TreeNode* p = q.front();
                q.pop();
                tmp.push_back(p->val);
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
