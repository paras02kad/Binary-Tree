#include <iostream>
#include <algorithm>
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

//! PreOrder Traversal Display
//* (ROOT)(LEFT)(RIGHT)

void displayPre(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    displayPre(root->left);
    displayPre(root->right);
}

//! InOrder Traversal Display
//* (LEFT)(ROOT)(RIGHT)

void displayIn(Node *root)
{
    if (root == NULL)
        return;

    displayIn(root->left);
    cout << root->val << " ";
    displayIn(root->right);
}

//! PostOrder Traversal Display
//* (LEFT)(RIGHT)(ROOT)

void displayPost(Node *root)
{
    if (root == NULL)
        return;

    displayPost(root->left);
    displayPost(root->right);
    cout << root->val << " ";
}

//! Print Nth level terms

void displayPre(Node *root, int current, int target)
{
    if (root == NULL)
        return;
    if (current == target)
        cout << root->val << " ";

    displayPre(root->left, current + 1, target);
    displayPre(root->right, current + 1, target);
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

//! Print Nth level terms ---> But in reverse order

void displayRev(Node *root, int current, int target)
{
    if (root == NULL)
        return;
    if (current == target)
    {
        cout << root->val << " ";
        return;
    }
    displayRev(root->right, current + 1, target);
    displayRev(root->left, current + 1, target);
}

int levels(Node *root)
{
    if (root == NULL)
        return 0;
    int answer = 1 + max(levels(root->right), levels(root->left));
    return answer;
}

int main()
{

    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    // displayPre(a); //* 1 2 4 5 3 6 7
    // cout << endl;
    // displayIn(a); //*4 2 5 1 6 3 7
    // cout << endl;
    // displayPost(a); //*4 5 2 6 7 3 1
    // cout << endl;

    // displayPre(a, 1, 3);

    //! Level Order Traversal
    // for (int i = 1; i <= levels(a); i++)
    // {
    //     displayPre(a, 1, i);
    //     cout << endl;
    // }

  //! Level Order Traversal but in reverse order
  for (int i = 1; i <= levels(a); i++)
    {
        displayRev(a, 1, i);
        cout << endl;
    }



    return 0;
}