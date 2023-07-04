#include <bits/stdc++.h> 
// int dp[1000][1000];
bool sol(string &a, string &b, string &c,int n,int m,int l,vector<vector<int>> &dp){
	if(l==0) return true;
	if(dp[n][m]!=-1) return dp[n][m];
	int x=0,y=0;
	if(n-1>=0 && a[n-1]==c[l-1]) x=sol(a,b,c,n-1,m,l-1,dp);
	if(m-1>=0 && b[m-1]==c[l-1]) y=sol(a,b,c,n,m-1,l-1,dp);
	return dp[n][m]=(x||y);
}
bool isInterleave(string a, string b, string c){

	int n1=a.size();
	int n2=b.size();
	int n3=c.size();
	if((n1+n2)!=n3) return false;
	vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
	// memset(dp,-1,sizeof(dp));
	return sol(a,b,c,n1,n2,n3,dp);
}
