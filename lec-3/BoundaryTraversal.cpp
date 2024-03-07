//! Breadth First Search (BFS)

#include <iostream>
#include <algorithm>
#include <Queue>
#include <climits>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *construct(int arr[], int n)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;

    while (q.size() > 0 && i < n)
    {
        Node *temp = q.front();
        q.pop();

        Node *l;
        Node *r;

        if (arr[i] != INT_MIN)

            l = new Node(arr[i]);

        else
            l = NULL;

        if (arr[j] != INT_MIN && j != n)

            r = new Node(arr[j]);

        else
            r = NULL;

        temp->left = l;
        temp->right = r;

        if (l != NULL)
            q.push(l);
        if (r != NULL)
            q.push(r);

        i += 2;
        j += 2;
    }

    return root;
}

//! Print Nth level terms --->(more Optimized)

void displayPreOpt(Node *root, int current, int target)
{
    if (root == NULL)
        return;
    if (current == target)
    {
        cout << root->val << " ";
        return;
    }

    displayPreOpt(root->left, current + 1, target);
    displayPreOpt(root->right, current + 1, target);
}

int levels(Node *root)
{
    if (root == NULL)
        return 0;
    int answer = 1 + max(levels(root->right), levels(root->left));
    return answer;
}
//--------------------------------------------------------------------------------------------


/*
!code is exactly same as preOrder Traversal.Only difference is the leaf case condition and when the left of root == null condition.
*/

void leftBoundary(Node *root)
{
    if (root == NULL)
        return;
    if (root->right == NULL && root->left == NULL)
        return; //* case for leaf node
    cout << root->val << " ";
    if (root->left != NULL)
        leftBoundary(root->left);
    //*call to right when the left of root is null.
    else if (root->left == NULL)
        leftBoundary(root->right);
}

/*
!just few modifications in the code of left Boundary to get Bottom Boundary code
*/

void bottomBoundary(Node *root)
{
    if (root == NULL)
        return;

    //* case for leaf node --> Here only we need to print values.
    if (root->right == NULL && root->left == NULL)
        cout << root->val << " ";

    //* going left and right without any conditions.
    bottomBoundary(root->left);
    bottomBoundary(root->right);
}

void rightBoundary(Node *root)
{
    if (root == NULL)
        return;
    //* case for leaf node
    if (root->right == NULL && root->left == NULL)
        return;

    if (root->right != NULL)
        rightBoundary(root->right);
    if (root->left != NULL)
        rightBoundary(root->left);
    // !printing values after the call to et reverse order of elements.
    cout << root->val << " ";
}

void Boundary(Node *root)
{
    //* To print left Boundary of the given Binary tree.
    leftBoundary(root);
    cout << endl;

    //* To print the bottom boundary of the given binary tree.
    bottomBoundary(root);
    cout << endl;

    //* To print the right boundary of the given binary tree.
    //! we gave root->right as root value of start to prevent re printing of 1 again which is already a part of left tree.
    rightBoundary(root->right);
    cout << endl;
    return;
}

int main()
{
    //! construct the given binary tree.

    int arr[] = {
        1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, 14,
        15, 16, INT_MIN, 17, INT_MIN, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23,
        INT_MIN, 24, 25, 26, 29, INT_MIN, INT_MIN, 28};

    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = construct(arr, n);

    //! calling the Boundary function.
    Boundary(root);

    return 0;
}