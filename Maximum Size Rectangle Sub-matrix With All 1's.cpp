#include<bits/stdc++.h>
int area(vector<int>&mat)
{
	int ans=0;
	stack<int>st;
	int n=mat.size();
	vector<int>leftSmall(n),rightSmall(n);
	for (int i=0;i<n;i++)
	{
		while(!st.empty() && mat[st.top()]>=mat[i])
		{
			st.pop();
		}
		if (st.empty()) leftSmall[i]=0;
		else leftSmall[i] = st.top()+1;
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for (int i=n-1;i>=0;i--)
	{
		while(!st.empty() && mat[st.top()]>=mat[i]) st.pop();
		if (st.empty()) rightSmall[i]=n-1;
		else rightSmall[i] = st.top()-1;
		st.push(i);
	}
    for (int i=0;i<n;i++)
	{
		ans=max(ans,(rightSmall[i]-leftSmall[i]+1)*mat[i]);
	}
	return ans;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
	int ans=0;
	ans=area(mat[0]);
	for (int i=1;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (mat[i][j]==1)
			mat[i][j]+=mat[i-1][j];
			else mat[i][j]=0;
		}
		ans=max(ans,area(mat[i]));
	}

	return ans;
}
