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
        left = nullptr;
        right = nullptr;
    }
};
// LOGn solution
int getleftheight(node *root)
{
    int h = 0;
    while (root)
    {
        h++;
        root = root->left;
    }
    return h;
}

int getrightheight(node *root)
{
    int h = 0;
    while (root)
    {
        h++;
        root = root->right;
    }
    return h;
}

int countallnodes(node *root)
{
    if (!root)
        return 0;
    int leftheight = getleftheight(root);
    int rightheight = getrightheight(root);
    //Simlpe 2^n-1 formula

    if (leftheight == rightheight)
    {
        cout << (1 << leftheight) - 1 << endl;
        return (1 << leftheight) - 1;
    }
    else
    {
        cout << 1 + countallnodes(root->left) + countallnodes(root->right) << endl;
        return 1 + countallnodes(root->left) + countallnodes(root->right);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // just some random values
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->right->right = new node(7);
    countallnodes(root);
    return 0;
}