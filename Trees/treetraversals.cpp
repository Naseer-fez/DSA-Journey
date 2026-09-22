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
void inordertravs(node *elem)
{

    if (elem == NULL)
    {

        return;
    }
    inordertravs(elem->left);
    cout << elem->data << " ";
    inordertravs(elem->right);
}

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
void leveltraversing(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *elem = q.front();
        q.pop();
        cout << elem->data << " ";
        if (elem->left != NULL)
            q.push(elem->left);
        if (elem->right != NULL)
            q.push(elem->right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    cout << "The inorder Traversal: [";
    inordertravs(root);
    cout << "]\nThe preorder Traversal: [";
    preorder(root);
    cout << "]\nThe postorder Traversal: [";
    postorder(root);
    cout << "]\nThe Level Traversal: [";
    leveltraversing(root);
    cout << "]";

    return 0;
}