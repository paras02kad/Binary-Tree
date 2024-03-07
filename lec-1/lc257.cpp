/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void helper(TreeNode *root, string str, vector<string> &ans)
    {
        if (root == NULL)
            return;
        string data = to_string(root->val);

        if (root->right == NULL && root->left == NULL)
        {
            str = str + data;
            ans.push_back(str);
            return;
        }

        helper(root->left, str + data + "->", ans);
        helper(root->right, str + data + "->", ans);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        string str = "";
        vector<string> ans;
        helper(root, str, ans);
        return ans;
    }
};