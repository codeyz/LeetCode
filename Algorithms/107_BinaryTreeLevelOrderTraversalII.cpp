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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int> > res;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            vector<int> tmp;
            size_t numOfNodes = q.size();
            for(size_t i = 0;i < numOfNodes; ++i)
            {
                TreeNode* p = q.front();
                q.pop();
                tmp.push_back(p->val);
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            res.insert(res.begin(), tmp);
        }
        return res;
    }
};
