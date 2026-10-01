#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{

    struct node *left;
    struct node *sideview;
    int data;
    node(int data)
    {
        this->data = data;
        left = NULL;
        sideview = NULL;
    }
};

void rightandleftview(node *root, bool rightview = 1)
{
    if (root == NULL)
        return;
    queue<pair<node *, pair<int, int>>> q;
    // row ,coloum
    map<pair<int, int>, int> mp;
    q.push({root, {0, 0}});
    int totalheigh = 0;
    while (!q.empty())
    {
        node *temp = q.front().first;
        auto [row, col] = q.front().second;
        q.pop();
        if (mp.find({row, col}) == mp.end())
        {
            mp[{row, col}] = temp->data;
        }
        if (temp->left != NULL)
        {
            q.push({temp->left, {row + 1, col - 1}});
        }
        if (temp->sideview != NULL)
        {
            q.push({temp->sideview, {row + 1, col + 1}});
        }
        totalheigh++;
    }
    // Now i need to store the data

    map<int, pair<int, int>> sideview;

    for (auto x : mp)
    {
        int row = x.first.first;
        int col = x.first.second;
        int data = x.second;
        if (sideview.find(row) == sideview.end())
        {
            sideview[row] = {col, data};
        }
        else if (col > sideview[row].first && rightview)
        {
            sideview[row] = {col, data};
        }
        else if (col < sideview[row].first && !rightview)
        {
            sideview[row] = {col, data};
        }
    }
    for (auto x : sideview)
    {
        cout << x.second.second << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // just some random values
    node *root = new node(1);
    root->left = new node(2);
    root->sideview = new node(3);
    root->left->left = new node(4);
    root->left->sideview = new node(5);
    root->left->sideview->left = new node(6);
    root->sideview->sideview = new node(7);
    cout<<"The right side view is :";
    rightandleftview(root);
    cout<<"\nThe left side view is :";
    rightandleftview(root,0);
    return 0;
}