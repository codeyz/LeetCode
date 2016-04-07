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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(!root)
            return false;
        if(!root->left && !root->right)
            return !(sum - root->val);
        return hasPathSum(root->left, sum - root->val) || 
               hasPathSum(root->right, sum - root->val);
    }
};
*/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        sumOfStack = 0;
        pushNodeAndAllLeftChildren(root);
        while(!s.empty())
        {
            TreeNode* tmp = s.top();
            // current node is leaf node and path sum equals to sum
            if(!tmp->left && !tmp->right && sumOfStack == sum)
                return true;
            if(flag.count(tmp))
            {
                // pop current node after visiting all its children
                sumOfStack -= tmp->val;
                s.pop();
            }
            else
            {
                flag[tmp] = true;
                pushNodeAndAllLeftChildren(tmp->right);
            }
        }
        return false;
    }
    
    void pushNodeAndAllLeftChildren(TreeNode* root)
    {
        if(!root)
            return;
        while(root)
        {
            sumOfStack += root->val;
            s.push(root);
            root = root->left;
        }
    }
    
private:
    stack<TreeNode*> s;
    map<TreeNode*, bool> flag;  // whether all of some node's children are visited
    int sumOfStack;
};
