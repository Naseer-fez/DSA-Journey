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

int zigzagtraversal(node *root)
{
    if (root == NULL)
        return 0;
    std::queue<node *> q;
    q.push(root);

    bool lefttoright = false; // shoudlve used bool
    while (!q.empty())
    {
        int levelsize = q.size();
        for (size_t i = 0; i < levelsize; i++)
        {
            node *elem = q.front();
            cout << "The val :" << elem->data << endl;
            q.pop();
            if (lefttoright)
            {
                if (elem->left != NULL)
                    q.push(elem->left);
                if (elem->right != NULL)
                    q.push(elem->right);
            }
            else
            {
                if (elem->right != NULL)
                    q.push(elem->right);

                if (elem->left != NULL)
                    q.push(elem->left);
            }
        }
        cout << endl;
        lefttoright = !lefttoright;
        // if(lefttoright)
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->left->left = new node(4);
    root->right->right = new node(6);
    root->right->right->right=new node(7);

    zigzagtraversal(root);

    return 0;
}