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

/*
!almost same code as queue
*/
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {

        vector<int> ans;
        stack<TreeNode *> st;

        //! important step as done earlier for lc144
        if (root != NULL)
            st.push(root);

        while (st.size() > 0)
        {
            TreeNode *temp = st.top();
            st.pop();
            ans.push_back(temp->val);

            //* Same as queue
            if (temp->left != NULL)
                st.push(temp->left);
            if (temp->right != NULL)
                st.push(temp->right);
        }
        /* 
        !before reversal answer has order -> root right left
        !on reversing it becomes  left right root ie postOrder
        */

        /* 
        *New step different from earlier
        *answer vector is not in right order so need to be reversed
        */
       
        reverse(ans.begin(), ans.end());
        return ans;
    }
};