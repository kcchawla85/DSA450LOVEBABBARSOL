#include <bits/stdc++.h> 

int helper(vector<int>&arr)
{
	int n=arr.size();
	unordered_map<int,int>mp;
	mp[0]=-1;
	int sum=0;
	int ans=0;
	for (int i=0;i<n;i++)
	{
       sum+=arr[i];
	   if (mp.find(sum)!=mp.end())
	   {
		   ans=max(ans,i-mp[sum]);
	   }
	   else{
		   mp[sum]=i;
	   }
	}
	return ans;
}

    int largestSubMatrix(int n, int m, vector<vector<int>> arr) 
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (arr[i][j]==0)
                {
                    arr[i][j]=-1;
                }
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            vector<int>temp(m,0);
            for (int j=i;j<n;j++)
            {
            
                for (int k=0;k<m;k++)
                {
                    temp[k]+=arr[j][k];
                }
                int len=helper(temp);
                ans=max(ans,len*(j-i+1));
            }
            
        }
        return ans;
    }
    // link : https://www.codingninjas.com/studio/problems/largest-sub-matrix-with-equal-0-s-and-1-s_3210616?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3
