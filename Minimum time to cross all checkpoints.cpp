#include <bits/stdc++.h> 
using namespace std;
 int rec(int ind,vector<vector<int>> &time,vector<vector<int>> &checkpoints
 ,int lane,vector<vector<int>>&dp)
 {
    if (ind==time.size()) return 0;
    if (dp[ind][lane]!=-1) return dp[ind][lane];
    int shift=checkpoints[ind-1][lane]+rec(ind+1,time,checkpoints,1-lane,dp);
    int notShift=time[ind][lane]+rec(ind+1,time,checkpoints,lane,dp);
    return dp[ind][lane]=min(shift,notShift);
 }
int minTime(vector<vector<int>> &time,vector<vector<int>> &checkpoints)
{
     int n=time.size();
     vector<vector<int>>dp(n,vector<int>(2,-1));
     int zero=time[0][0]+rec(1,time,checkpoints,0,dp);
     int one=time[0][1]+ rec(1,time,checkpoints,1,dp);
     return min(one,zero);
}
// link : https://www.codingninjas.com/studio/problems/minimum-time-to-cross-all-checkpoints_1214626?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3
