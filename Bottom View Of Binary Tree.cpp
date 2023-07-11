#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    map<int,int> topNode;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<BinaryTreeNode<int>*,int> temp = q.front();
        q.pop();
        BinaryTreeNode<int>* frontNode=temp.first;
        int hd=temp.second;
        topNode[hd]=frontNode->data;
        if(frontNode->left)
        {
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right)
        {
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i:topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
    
}
//link : https://www.youtube.com/watch?v=s1d8UGDCCN8&t=82s
