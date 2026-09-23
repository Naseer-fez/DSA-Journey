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
int maxdeptrec(node *elem)
{
    if (elem == NULL)
        return 0;
    int left = maxdeptrec(elem->left);
    int right = maxdeptrec(elem->right);

    return (1 + std::max(left, right));
}
int maxdeptque(node *elem)
{
    queue<node *> q;
    q.push(elem);
    int left = 0;
    int right = 0;
    while (!q.empty())
    {
        node *elem = q.front();
        q.pop();
        if (elem->left != NULL)
        {
            q.push(elem->left);
            left++;
        }
        if (elem->right != NULL)
        {
            q.push(elem->right);
            right++;
        }
    }
    return 1 + (std::max(left, right));
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
    cout << "The maximum dept(using recercive) is:" << maxdeptrec(root)<<endl;
    cout << "The maximum dept(using Queue) is:" << maxdeptque(root);

    return 0;
}