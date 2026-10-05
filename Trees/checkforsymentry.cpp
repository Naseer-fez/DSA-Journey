#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{

    struct node *left;
    struct node *right;
    int data;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool checknodes(node *left, node *right)
{
    // can just use nested if and elses
    if (left == NULL && right == NULL)
        return true;

    if (left && right && left != NULL) // both exist
    {
        bool val = checknodes(left->left, right->right);
        bool secval = checknodes(left->right, right->left);
        return ((val && secval));
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // just some random values
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->right->right = new node(7);
    // cout << "The right side view is :";
    auto val = checknodes(root->left, root->right);
    if (val)
        cout << "The tree is sysmetric";
    else
        cout << "The tree is not";
    // cout << "\nThe left side view is :";
    // checkifsysm(root, 0);
    return 0;
}