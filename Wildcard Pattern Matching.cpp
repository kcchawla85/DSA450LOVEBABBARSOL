#include<bits/stdc++.h>
int solve(int i,int j,string s,string t,int n,int m,vector<vector<int>>&dp){

   if((i==n && j==m) || (j==m && s[i]=='*' && i==n-1))return 1;

   else if(i>=n|| j>=m)return 0;

   if(dp[i][j]!=-1)return dp[i][j];

   int pos=0;

   int notpos=0,non=0;

   if(s[i]==t[j] || s[i]=='?'){

      pos=solve(i+1,j+1,s,t,n,m,dp);

   }

   else if(s[i]=='*'){

      notpos= solve(i,j+1,s,t,n,m,dp);

      non=solve(i+1,j,s,t,n,m,dp);

   }

   return dp[i][j]= pos||notpos||non;

}

bool wildcardMatching(string pattern, string text)

{  int n=pattern.size();

   int m=text.size();

   vector<vector<int>>dp(n+1,vector<int>(m,-1));

   return solve(0,0,pattern,text,n,m,dp);

}
//link : https://www.youtube.com/watch?v=OgovJ9CB0hI
