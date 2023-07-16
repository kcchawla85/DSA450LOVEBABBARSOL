
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include <bits/stdc++.h> 

 

vector<int> zigzagTreeTraversal(TreeNode<int> *root)

{

    vector<vector<int>> temp;

    vector<int> ans;

    queue<TreeNode<int>*> q;

    q.push(root);

    if(root==NULL)return ans;

    while(!q.empty()){

        int size = q.size();

        vector<int> level;

        for(int i = 0;i<size;i++){

            TreeNode<int>* node = q.front();

            q.pop();

            if(node->left!=NULL)q.push(node->left);

            if(node->right!=NULL)q.push(node->right);

            level.push_back(node->data);

        }

        temp.push_back(level);

    }

    for(int i = 0;i<temp.size();i++){

        if(i%2==1)reverse(temp[i].begin(),temp[i].end());

        for(auto it:temp[i]){

            ans.push_back(it);

        }

    }

    return ans;

}

// link : https://www.youtube.com/watch?v=s1d8UGDCCN8&t=83s
