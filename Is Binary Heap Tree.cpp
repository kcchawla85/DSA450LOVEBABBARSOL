#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
bool isCBT(BinaryTreeNode<int> *root, int index, int totalCount)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    if (index >= totalCount)
    {
        return false;
    }

    return (isCBT(root->left, 2 * index + 1, totalCount) && isCBT(root->right, 2 * index + 2, totalCount));
}

bool isMaxOrder(BinaryTreeNode<int> *root, int maxValue = INT_MAX)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->data > maxValue)
    {
        return false;
    }

    return isMaxOrder(root->left, root->data) && isMaxOrder(root->right, root->data);
}

bool isBinaryHeapTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return true;
    }

    int totalCount = 0;

    std::queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *current = q.front();
        q.pop();

        if (current->left)
        {
            q.push(current->left);
        }

        if (current->right)
        {
            q.push(current->right);
        }

        totalCount++;
    }

    return isCBT(root, 0, totalCount) && isMaxOrder(root);
}
// link : 
