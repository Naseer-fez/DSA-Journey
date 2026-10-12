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

// node *findthenode(node *root, int k)
// {
//     if (!root)
//         return NULL;
//     if (root->data == k)
//         return root;
//     findthenode(root->left);
//     findthenode(root->right);
//     return NULL;
// }

void printallnodesatkdis(node *root, int k, int dist)
{
    if (!root)
        return;
    std::queue<std::pair<node *, node *>> q;
    std::unordered_map<node *, node *> parentmap;
    q.push({root, root});
    node *rootsparent = NULL, *tarnode = NULL;

    while (!q.empty())
    {
        auto [temp, parent] = q.front();
        q.pop();
        if (temp->data == k)
        {
            rootsparent = parent;
            tarnode = temp;
            break; // better to break
        }
        if (temp->left != NULL)
        {
            parentmap[temp->left] = temp;
            q.push({temp->left, temp});
        }
        if (temp->right != NULL)
        {
            parentmap[temp->right] = temp;
            q.push({temp->right, temp});
        }
    }
    // Now that we got the parent , lets go though the distance
    if (!tarnode)
    {
        std::cout << "No Target node found!!!!!!!!!!";
        return;
    }

    if (!tarnode)
        return;

    std::queue<node *> q2;
    std::unordered_set<node *> visited;

    q2.push(tarnode);
    visited.insert(tarnode);

    int level = 0;

    while (!q2.empty())
    {
        int size = q2.size();

        if (level == dist)
        {
            while (!q2.empty())
            {
                std::cout << q2.front()->data << " ";
                q2.pop();
            }
            return;
        }

        while (size--)
        {
            node *temp = q2.front();
            q2.pop();

            if (temp->left && !visited.count(temp->left))
            {
                visited.insert(temp->left);
                q2.push(temp->left);
            }

            if (temp->right && !visited.count(temp->right))
            {
                visited.insert(temp->right);
                q2.push(temp->right);
            }

            node *parent = parentmap[temp];

            if (parent && !visited.count(parent))
            {
                visited.insert(parent);
                q2.push(parent);
            }
        }

        level++;
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
    // cout << "The right side view is :";
    printallnodesatkdis(root, 2, 2);

    // cout << "\nThe left side view is :";
    // checkifsysm(root, 0);
    return 0;
}