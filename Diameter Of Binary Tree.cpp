/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int height(TreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right=height(root->right);
    int ans= max(left,right)+1;
    return ans;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	if(root==NULL){
        return 0;
    }
    int op1=diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = height(root->left)+height(root->right);
    int ans = max(op1, max(op2,op3));
    return ans;
}
// link: https://www.youtube.com/watch?v=nHMQ33LZ6oA&t=505s
