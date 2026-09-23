#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{

    struct node *left;
    struct node *right;
    int data;
    bool isbalance;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        isbalance = false;
    }
};

//O(n^2)
bool checkthebalance(node *root)
{
    // if (root == NULL)
    //     return;
    int left = 0, right = 0;
    // lets trave through all the nodes then
    node *temp = root;
    // First left
    while (temp)
    {
        if (temp->left != NULL)
            left++;
        else
            break;

        temp = temp->left;
    }
    node *temp2 = root;
    while (temp2)
    {
        if (temp2->right != NULL)
            right++;
        else
            break;

        temp2 = temp2->right;
    }
    return left == right;
}

void checkallnodesbalance(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *elem = q.front();
        q.pop();
        if (elem->left != NULL)
        {
            q.push(elem->left);
            elem->left->isbalance = checkthebalance(elem->left);
        }
        if (elem->right != NULL)
        {
            q.push(elem->right);
            elem->right->isbalance = checkthebalance(elem->right);
        }
    }
}


//O(n)
int checkbalanceint(node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = checkbalanceint(root->left);
    int rightHeight = checkbalanceint(root->right);

    root->isbalance = abs(leftHeight - rightHeight) <= 1;

    return 1 + max(leftHeight, rightHeight);
}


void postorder(node *elem)
{
    if (elem == NULL)
        return;
    postorder(elem->left);
    postorder(elem->right);
    const char *tosay;

    if (elem->isbalance)
        tosay = "   ";
    else
        tosay = "not";

    cout << "At the address:" << elem << " The root is " << tosay << " Balanced"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // just some random values
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(2);
    root->left->left->left = new node(2);
    root->right = new node(2);
    root->right->right = new node(2);
    root->right->left = new node(2);
    root->right->left->left = new node(2);
    // root->left->right= new node(2);
    // std::cout << "The Tree is balanced:" << checkthebalance(root);
    checkbalanceint(root);
    postorder(root);
    return 0;
}