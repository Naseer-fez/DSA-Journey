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

int minimumtimetoburnanode(node *root, int key)
{
    if (!root)
        return -1;
    std::queue<node *> q;
    std::unordered_map<node *, node *> parentmap;
    // first lets find the elem
    node *parentnode, *targetnode = NULL;
    q.push(root);
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        if (temp->data == key)
        {
            targetnode = temp;
            // break;
        }

        if (temp->left)
        {
            parentmap[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            parentmap[temp->right] = temp;
            q.push(temp->right);
        }
    }
    if (!targetnode)
        return -1;
    // Root has been found now
    std::queue<node *> q2;
    std::unordered_set<node *> visited;
    q2.push(targetnode);
    visited.insert(targetnode);
    int time = 0;
    while (!q2.empty())
    {
        int size = q2.size();
        bool burned = false;
        // while (!q2.empty())
        // {
        //     cout << "Burning:" << q2.front()->data << " ";
        //     q2.pop();
        // }
        // cout << "\n";c
        while (size--)
        {
            node *temp = q2.front();
            q2.pop();
            if (temp->left && !visited.count(temp->left))
            {
                visited.insert(temp->left);
                q2.push(temp->left);
                burned = true;
            }
            if (temp->right && !visited.count(temp->right))
            {
                visited.insert(temp->right);
                q2.push(temp->right);
                burned = true;
            }
            // Now lets add the parent node
            node *abovenode = parentmap[temp];
            if (abovenode && !visited.count(abovenode))
            {
                q2.push(abovenode);
                visited.insert(abovenode);
                burned=true;
            }
        }

        if (burned) time++;
    }

    return time;
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
    auto t = minimumtimetoburnanode(root, 2);
    cout << "The time takes is:" << t;
    // cout << "\nThe left side view is :";
    // checkifsysm(root, 0);
    return 0;
}