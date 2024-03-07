#include <iostream>
#include <climits>
#include <cmath>
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

void display(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    display(root->left);

    display(root->right);
}

int sum(Node *root)
{
    if (root == NULL)
        return 0;
    int ans = (root->val) + sum(root->left) + sum(root->right);
    return ans;
}

int size(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

int maximum(Node *root)
{
    if (root == NULL)
        return INT_MIN;

    return max(root->val, max(maximum(root->right), maximum(root->left)));
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

    display(a);

    // int data = sum(a);
    // cout<<data<<endl;

    // cout<<size(a)<<endl;

    // cout << maximum(a) << endl;

    // cout<<levels(a)<<endl;

    return 0;
}