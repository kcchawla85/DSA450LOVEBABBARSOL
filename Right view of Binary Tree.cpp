/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

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
void solve(BinaryTreeNode<int>* root, vector<int>& ans, int level)
{
    if(root==NULL)
    {
        return ;
    }
    if(level==ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}
vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}
//link: https://www.youtube.com/watch?v=s1d8UGDCCN8&t=82s
