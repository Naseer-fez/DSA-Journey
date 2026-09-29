#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{

    struct node *left;
    int data;
    struct node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void preorder(node *elem)
{
    if (elem == NULL)
        return;
    cout << elem->data << " ";
    preorder(elem->left);
    preorder(elem->right);
}
void postorder(node *elem)
{
    if (elem == NULL)
        return;
    postorder(elem->left);
    postorder(elem->right);
    cout << elem->data << " ";
}

void preorderclk(node *elem)
{
    if (elem == NULL)
        return;
    cout << elem->data << " ";
    preorderclk(elem->right);
    preorderclk(elem->left);
}
void postorderclk(node *elem)
{
    if (elem == NULL)
        return;
    postorderclk(elem->right);
    postorderclk(elem->left);
    cout << elem->data << " ";
}

int checkboundary(node *root, bool clockwise)
{
    if (root == NULL)
        return 0;
    cout << root->data << " ";
    if (clockwise)
    {
        preorder(root->left);
        // inordertravs(root->right);
        postorder(root->right);
    }
    else
    {
        preorderclk(root->right); // little consufed
        postorderclk(root->left);
        // inordertravs(root->right);
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(7);
    root->left->left = new node(3);
    root->left->left->left = new node(4);
    root->left->left->left->right = new node(6);
    root->left->left->left->left = new node(5);
    root->right->right = new node(8);
    root->right->right->left = new node(9);
    root->right->right->left->left = new node(10);
    root->right->right->left->right = new node(11);
    cout << "The Anti Clockwise: ";
    checkboundary(root, 1);
    cout << "\nThe clock wise: ";
    checkboundary(root, 0);
    return 0;
}