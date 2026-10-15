#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int findCeil(node *root, int key)
{
    node *temp = root;
    int ceil = -1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            ceil = temp->data;
            break; // ceil is val>=key
        }
        else if (temp->data < key)
        {
            // move to right subtree
            temp = temp->right;
        }
        else
        {
            ceil = temp->data;
            temp = temp->left;
        }
    }

    return ceil;
}

int findFloor(node *root, int key)
{
    node *temp = root;
    int floor = -1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            floor = temp->data;
            break; // floor is val<=key
        }
        else if (temp->data > key)
        {
            // move to right subtree
            temp = temp->left;
        }
        else
        {
            floor = temp->data;
            temp = temp->right;
            // break;
        }
    }

    return floor;
}

int main()
{
    node *root = new node(8);
    root->left = new node(4);
    root->right = new node(12);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->right->left = new node(10);
    root->right->right = new node(14);

    int key = 9;

    cout << "Ceil: " << findCeil(root, key) << endl;
    cout << "Floor: " << findFloor(root, key) << endl;

    return 0;
}