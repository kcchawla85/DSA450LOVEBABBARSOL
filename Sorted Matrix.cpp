#include <bits/stdc++.h> 
vector<int> sortedMatrix(vector<vector<int>> &mat, int n) {
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans.push_back(mat[i][j]);

        }
    }
    sort(ans.begin(),ans.end());
    return ans;

}
