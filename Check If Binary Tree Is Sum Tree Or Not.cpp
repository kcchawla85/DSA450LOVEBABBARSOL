#include <bits/stdc++.h>

// ... (TreeNode class definition here)

template<typename T>
pair<bool, T> isSumTreeFast(TreeNode<T>* root) {
    if (root == nullptr) {
        pair<bool, T> p = make_pair(true, T());
        return p;
    }
    if (root->left == nullptr && root->right == nullptr) {
        pair<bool, T> p = make_pair(true, root->val);
        return p;
    }
    pair<bool, T> leftAns = isSumTreeFast(root->left);
    pair<bool, T> rightAns = isSumTreeFast(root->right);
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
    T leftSum = leftAns.second;
    T rightSum = rightAns.second;
    bool condn = root->val == leftSum + rightSum;
    pair<bool, T> ans;
    if (isLeftSumTree && isRightSumTree && condn) {
        ans.first = true;
        ans.second = root->val + leftSum + rightSum;
    }
    else {
        ans.first = false;
    }
    return ans;
}

template<typename T>
bool isSumTree(TreeNode<T>* root) {
    return isSumTreeFast(root).first;
}

//link: https://www.youtube.com/watch?v=nHMQ33LZ6oA&t=505s
