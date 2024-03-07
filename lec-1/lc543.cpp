/*
* First Approach
! Wrong approach as we are using global variable which is not a good practice.
*/

class Solution
{
public:
    int maxDia = 0;
    int level(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return (1 + max(level(root->left), level(root->right)));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int dia = level(root->left) + level(root->right);
        maxDia = max(dia, maxDia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxDia;
    }
};

/*
* Second  Approach
! Here we are not using any Global variable.
*/

class Solution
{
public:
    int level(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return (1 + max(level(root->left), level(root->right)));
    }

    int helper(TreeNode *root, int &maxDia)
    {
        if (root == NULL)
            return 0;
        int dia = level(root->left) + level(root->right);
        maxDia = max(dia, maxDia);
        helper(root->left, maxDia);
        helper(root->right, maxDia);
        return maxDia;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
    }
};