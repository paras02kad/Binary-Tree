//! Breadth First Search (BFS)

#include <iostream>
#include <algorithm>
#include <Queue>

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

void levelOrderQueue(Node *root)
{
    queue<Node *> Q;
    Q.push(root);

    while (Q.size() > 0)
    {
        Node *temp = Q.front();
        Q.pop();
        cout << temp->val << " ";
        if (temp->left != NULL)
            Q.push(temp->left);
        if (temp->right != NULL)
            Q.push(temp->right);
    }
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

    levelOrderQueue(a);

    return 0;
}