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

int sametreeornot(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 0;
    else if (root1 == NULL && root2 != NULL)
        return -1;
    else if (root1 != NULL && root2 == NULL)
        return -1;
    //we have values
   
    int left=sametreeornot(root1->left,root2->left);
    int right=sametreeornot(root1->right,root2->right);
    
    
   return left && right; 


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Tree 1
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->left->left = new node(3);
    root1->left->right = new node(4);
    root1->right = new node(5);
    root1->right->left = new node(6);

    // Tree 2
    node *root2 = new node(1);
    root2->left = new node(2);
    root2->left->left = new node(3);
    root2->left->right = new node(4);
    root2->right = new node(5);
    root2->right->left = new node(6);
    auto val = sametreeornot(root1, root2);
    cout<<"The Tree 1 and Tree 2 are :"<<val;
    return 0;
}