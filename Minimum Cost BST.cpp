#include <bits/stdc++.h>

int getsum(vector<int>& freq,int i,int j)

{

   int sum=0;

   for(int k=i;k<=j;k++)

   {  

          sum+=freq[k];

 }

 return sum;

}

int helper(vector<int>& keys, vector<int>& freq,int l,int r,vector<vector<int>> &dp)

{

    if(l>r){

       return 0;

     }

     if(dp[l][r]!=-1){

        return dp[l][r];

    }

    int ans=INT_MAX;

    for(int i=l;i<=r;i++){

          int temp=getsum(freq,l,r)+helper(keys,freq,i+1,r,dp)+helper(keys,freq,l,i-1,dp);                                
          ans=min(ans,temp);

    }

    return dp[l][r]=ans;

}

int minCostBST(vector<int> &arr, vector<int> &freq){
       int N=101;

       vector<vector<int>> dp(N,vector<int>(N,-1)); 
       int n=arr.size();
       return helper(arr,freq,0,n-1,dp);  

}

 
