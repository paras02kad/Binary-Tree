/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool existsInTree(TreeNode *root, TreeNode *target)
    {
        if (root == NULL)
            return false;
        if (root == target)
            return true;
        if (existsInTree(root->left, target) || existsInTree(root->right, target))
            return true;
        else
            return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q)
            return root;
        else if (existsInTree(root->left, p) && existsInTree(root->right, q))
            return root;
        else if (!existsInTree(root->left, p) && !existsInTree(root->right, q))
            return root;
        else if (existsInTree(root->left, p) && !existsInTree(root->right, q))
            return lowestCommonAncestor(root->left, p, q);
        else if (!existsInTree(root->left, p) && existsInTree(root->right, q))
            return lowestCommonAncestor(root->right, p, q);
      return root;
    }
};