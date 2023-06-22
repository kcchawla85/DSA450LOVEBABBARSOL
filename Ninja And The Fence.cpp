#include <bits/stdc++.h> 
#define MOD 1000000007
int add (int a, int b)
{
    return (a%MOD + b%MOD)%MOD;
}
int multi (int a, int b)
{
    return ((a%MOD)* 1LL *(b%MOD))%MOD;
}
int solve(int n, int k, vector<int> &dp)
{
    //base case
    if(n==1)
    {
        return k;
    }
    if(n==2)
    {
        return add(k, multi(k,k-1));
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n] = add(multi(solve(n-2,k,dp),k-1),multi(solve(n-1,k,dp),k-1));
    return dp[n];
}
int solveTab(int n, int k)
{
    //base case
    int prev2=k;
    int prev1=add(k, multi(k,k-1));
    for(int i=3;i<=n;i++)
    {
        int ans = add(multi(prev2,k-1),multi(prev1,k-1));
        prev2=prev1;
        prev1=ans;
    }
    
    return prev1;
}
int numberOfWays(int n, int k) {
    // Write your code here.
    return solveTab(n,k);
}
