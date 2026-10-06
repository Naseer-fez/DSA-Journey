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

int leastcommontraversal(node *root, std::pair<int, int> elem)
{
    if (!root)
        return -1;
    if (root->data == elem.first || root->data == elem.second)
        return root->data;
    int lefti = leastcommontraversal(root->left, elem);
    int righti = leastcommontraversal(root->right, elem);
    if (lefti == -1)
        return righti;
    else if (righti == -1)
        return lefti;
    else
        return root->data;

    return root->data;
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
    // cout << "The right side view is :";
    auto val = leastcommontraversal(root, {4, 6});
    cout << "The least common ancestor is : " << val;

    // cout << "\nThe left side view is :";
    // checkifsysm(root, 0);
    return 0;
}