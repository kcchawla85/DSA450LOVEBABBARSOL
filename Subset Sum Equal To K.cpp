#include <bits/stdc++.h> 

 

// memoization

bool solve(int ind, int n, int k, vector<int> &arr, vector<vector<int>> &dp){

    if(k == 0) return true;

    if(k < 0 || ind == n) return false;

    if(dp[ind][k] != -1) return dp[ind][k];

 

    bool pick = solve(ind+1, n, k-arr[ind], arr, dp);

    bool notPick = solve(ind+1, n, k, arr, dp);

 

    return dp[ind][k] = pick || notPick;

}

 

// tabulation

bool solve2(int ind, int n, int k, vector<int> &arr){

    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));

    //base case

    for(int i = 0 ; i < n ; i++) dp[i][0] = true;

    dp[0][arr[0]] = true;

 

    for(int i = 1 ; i < n ; i++){

        for(int j = 1 ; j <= k ; j++){

            bool pick = false;

            if(j-arr[i] >= 0) pick = dp[i-1][j-arr[i]];

            bool notPick = dp[i-1][j];

 

            dp[i][j] = pick || notPick;

        }

    }

 

    return dp[n-1][k];

}

 

bool subsetSumToK(int n, int k, vector<int> &arr) {

    // vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

    // return solve(0, n, k, arr, dp);

 

    return solve2(0, n, k, arr);

}
//link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3
