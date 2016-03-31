/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/* resursion
class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p && q)
        {
            if(p->val != q->val)
                return false;
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        if(!p && !q)
            return true;
        return false;
    }
};
*/

// non-recursion
class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        stack<TreeNode*> sp, sq;
        pushNodeAndAllLeftChildren(sp, p);
        pushNodeAndAllLeftChildren(sq, q);
        while(!sp.empty() && !sq.empty() && sp.size() == sq.size())
        {
            TreeNode* tmp1 = sp.top();
            sp.pop();
            TreeNode* tmp2 = sq.top();
            sq.pop();
            if(tmp1->val != tmp2->val)
                return false;
            pushNodeAndAllLeftChildren(sp, tmp1->right);
            pushNodeAndAllLeftChildren(sq, tmp2->right);
        }
        return sp.empty() && sq.empty();
    }
    
    void pushNodeAndAllLeftChildren(stack<TreeNode*>& s, TreeNode* r)
    {
        while(r)
        {
            s.push(r);
            r = r->left;
        }
    }
};
