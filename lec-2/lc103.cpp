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
    // function for printing nodes from left to right
    void nthLevel_l(TreeNode *root, int clev, int dlev, vector<int> &mech)
    {
        if (root == NULL)
            return ; //-->base case
        if (clev == dlev){
mech.push_back(root->val);
return;
        }
            

        nthLevel_l(root->left, clev + 1, dlev, mech);  //-->call-1
        nthLevel_l(root->right, clev + 1, dlev, mech); //--call-2
    }

    void nthLevel_R(TreeNode *root, int clev, int dlev, vector<int>&chem)
    {
        if (root == NULL)
            return; //-->base case
        if (clev == dlev){
            chem.push_back(root->val);
            return;

        }
            
        nthLevel_R(root->right, clev + 1, dlev, chem); //--call-2
        nthLevel_R(root->left, clev + 1, dlev, chem);  //-->call-1
    }

    // function to find no of levels in the given tree
    int TreeLev(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return (1 + max(TreeLev(root->right), TreeLev(root->left)));
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        int data = TreeLev(root);

        vector<vector<int>> ans;
      
       

        for (int i = 1; i <= data; i++)
        {
            if (i % 2 == 0)
            {
                // will go with right to left
                  vector<int> mech;
                nthLevel_R(root, 1, i, mech);
                ans.push_back(mech);
            }
            else{
 // go with left to right
  vector<int> chem;
                 nthLevel_l(root, 1, i, chem);
            ans.push_back(chem);
            }
               
        }

        return ans;
    }
};