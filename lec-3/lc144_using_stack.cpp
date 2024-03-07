/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        stack<TreeNode*> st;

        //! important condition to be remembered as what if root is null so given condition saves from such an error.

        if(root!=NULL)st.push(root);

        while (st.size() > 0) 
        {
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);

            //* right is pushed before left because of FILO property of stack and we need left to right traversal. Only diferenec from traversal using queue.
            
            if (temp->right != NULL)
                st.push(temp->right);
            if (temp->left != NULL)
                st.push(temp->left);
        }
        return ans;
    }
};