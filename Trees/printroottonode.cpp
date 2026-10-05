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
std::vector<node *> vec;

bool inordertraverssal(node *root,int elem)
{
    if(!root)return false;
    vec.push_back(root); // now also i need to rmeovee it
    if(root->data==elem)return true;


    if(inordertraverssal(root->left,elem))return true;
    if(inordertraverssal(root->right,elem))return true;
    vec.pop_back();
    return false;
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
    // cout << "The right side view is :";
    inordertraverssal(root,6);
    cout << "The root to node is: -->";
    for (const auto &element : vec)
    {
        std::cout << element->data << " ";
    }

    // cout << "\nThe left side view is :";
    // checkifsysm(root, 0);
    return 0;
}