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

void topviewofatree(node *root)
{
    if (root == NULL)
        return;

    queue<pair<node *, int>> q;
    q.push({root, 0});
    // Now we have the quee for level traversal
    map<int, int> mp;

    while (!q.empty())
    {
        node *temp = q.front().first;
        int row = q.front().second;
        q.pop();
        if (mp.find(row) == mp.end())
        {
            mp[row] = temp->data;
        }
        if (temp->left != NULL)
        {
            q.push({temp->left, row - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, row + 1});
        }

        // Now the traversal
    }
    // if needed sort it
    //  for(auto &x:mp){
    //      sort(x.second.begin(), x.second.end());

    // }

    for (auto x : mp)
    {
        cout << x.second << " ";

        cout << endl;
    }
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

    topviewofatree(root);
    return 0;
}