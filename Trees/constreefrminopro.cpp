#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int x) : data(x), left(nullptr), right(nullptr) {}
};

node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    // Inorder -> Left, root , right
    // Preorder ->Root,left,right
    if (preorder.empty() || inorder.empty())
        return NULL;

    node *tree = new node(preorder[0]);
    auto it = find(inorder.begin(), inorder.end(), preorder[0]);
    if (it == inorder.end())
        return NULL;
    int rootindex = it - inorder.begin();
    int leftsize = rootindex;
    //This vectore section need to optmized by using using another function and calling that with amny paaremnets
    vector<int> leftpre(preorder.begin() + 1, preorder.begin() + 1 + leftsize);
    vector<int> leftin(inorder.begin(), inorder.begin() + rootindex);
    vector<int> rightpre(preorder.begin() + 1 + leftsize, preorder.end());
    vector<int> rightin(inorder.begin() + rootindex + 1, inorder.end());
    tree->left = buildTree(leftpre, leftin);
    tree->right = buildTree(rightpre, rightin);
    return tree;
}

void preordertravs(node *elem)
{
    if (elem == NULL)
        return;
    cout << elem->data << " ";
    preordertravs(elem->left);
    preordertravs(elem->right);
}
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
void printvecval(vector<int> &vec)
{

    for (const auto &val : vec)
    {
        std::cout << val << " ";
    }
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    cout << "The Vector values Preorder:";
    printvecval(preorder);
    cout << "\nThe Vector values Inorder:";
    printvecval(inorder);
    node *root = buildTree(preorder, inorder);
    cout << "\nPreorder:";
    preordertravs(root);
    cout << "\nInorder:";
    inordertravs(root);

    return 0;
}