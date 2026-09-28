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
    }
};

int maxsum=0;

int maxpathsum(node *root){
if(root==NULL)return 0;
int left=maxpathsum(root->left);
int right=maxpathsum(root->right);
maxsum=std::max(maxsum,root->data+left+right);
return (root->data)+max(left,right);



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
    maxpathsum(root);
    cout << "The maxisum path sum is: "<< maxsum; 
    return 0;
}