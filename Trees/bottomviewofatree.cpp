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

void bottomview(node *root)
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
        int hei = q.front().second;
        q.pop();
        mp[hei] = temp->data;
         if (temp->left != NULL)
        {
            q.push({temp->left, hei - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, hei + 1});
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

    bottomview(root);
    return 0;
}