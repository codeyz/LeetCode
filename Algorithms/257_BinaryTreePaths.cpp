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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        dfs(root, "");
        return path;
    }
    
    void dfs(TreeNode* root, string pa)
    {
        if(!root)
        {
            if(pa != "")
                path.push_back(pa);
            return;
        }
        if(pa == "")
            pa = to_string(root->val);
        else
            pa += string("->") + to_string(root->val);
        if(!root->left && !root->right)
        {
            path.push_back(pa);
            return;
        }
        if(root->left)
            dfs(root->left, pa);
        if(root->right)
            dfs(root->right, pa);
    }
    
private:
    vector<string> path;
};
