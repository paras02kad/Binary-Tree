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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        /*
        !No need to push root value initially to the stack and null values will automatically be taken care by the while loop.
        */

        while (st.size() > 0 || root != NULL)
        {
            if (root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            else if (root == NULL)
            {
                TreeNode *temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                root = temp->right;
            }
        }

        return ans;
    }
};