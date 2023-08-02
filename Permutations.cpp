#include <bits/stdc++.h> 
void solve(vector<int> nums, vector<vector<int>>& ans, int index)
    {
        if(index>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j =index;j<nums.size();j++)
        {
            swap(nums[index], nums[j]);
            solve(nums,ans,index+1);
            //backtracking
            swap(nums[index], nums[j]);
        }


    }
vector<vector<int>> permutations(vector<int> &vec, int size) {
    vector<vector<int>> ans;
        int index=0;
        solve(vec, ans, index);
        return ans;
}
