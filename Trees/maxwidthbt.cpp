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

int maxwidith(node *root)
{
    if (!root)
        return 0;
    std::queue<pair<node *, int>> q;
    q.push({root, 0});
        std::map<int, int>  mp; // lets just add them
    while (!q.empty())
    {
        node *temp = q.front().first;
        int level = q.front().second;
        q.pop();
        mp[level]++;
        if (temp->left)
        {

            q.push({temp->left, level + 1});

        }
        if (temp->right)
        {

            q.push({temp->right, level + 1});
        }
    }
    // now need to find the maximum
    int maxelm = -999;

    for (const auto &[level, width] : mp)
    {
        maxelm = std::max(maxelm, width);
    }

    return maxelm;
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
    auto val = maxwidith(root);
    cout << "The Maximum widith is : " << val;

    // cout << "\nThe left side view is :";
    // checkifsysm(root, 0);
    return 0;
}