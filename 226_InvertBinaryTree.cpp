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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
*/

// non-recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> s;
        pushNodeAndLeftChildren(s, root);
        while(!s.empty())
        {
            TreeNode* tmp = s.top();
            s.pop();
            // swap left and right child
            swap(tmp->left, tmp->right);
            pushNodeAndLeftChildren(s, tmp->left);
        }
        return root;
    }
    
    void pushNodeAndLeftChildren(stack<TreeNode*>& s, TreeNode* root)
    {
        // push the current node and all of its left children
        TreeNode* tmp = root;
        while(tmp)
        {
            s.push(tmp);
            tmp = tmp->left;
        }
    }
};
