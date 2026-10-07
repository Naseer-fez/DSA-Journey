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


void childsum(node *root)
{
    if (!root)
        return;
    int child = 0;
    if (root->left != NULL)
        child += root->left->data;
    if (root->right != NULL)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left != NULL)
            root->left->data = root->data;
        if (root->right != NULL)
            root->right->data = root->data;
    }
    childsum(root->left);
    childsum(root->right);
    int total = 0;
    if (root->left != NULL)
        total += root->left->data;
    if (root->right != NULL)
        total += root->right->data;
    if (root->left != NULL || root->right != NULL)
        root->data = total;
}
void postorder(node *elem)
{
    if (elem == NULL)
        return;
    postorder(elem->left);
    postorder(elem->right);
   cout<<"["<<elem->data<<"]";
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
    root->left->right = new node(10);

    root->left->left->right = new node(5);
    root->left->left->right->right = new node(6);

    root->right->left = new node(9);
    root->right->right = new node(10);
    childsum(root);
    postorder(root);
    return 0;
}