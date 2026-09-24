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
int maxval=-999;
int diameter(node *root){
if(root==NULL)
    return 0;
int left=diameter(root->left);
int right=diameter(root->right);

maxval=std::max(maxval,left+right);
return 1+std::max(left,right);
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
    cout<<"The tree's daiameter is: "<<diameter(root)<<endl;
    return 0;
}