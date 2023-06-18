#include <bits/stdc++.h> 
int minimizeIt(vector<int> A, int K)
{
	int n=A.size();
	
	sort(A.begin(),A.end());
	int ans=A[n-1]-A[0];
	int maxi=A[n-1];
	int mini=A[n];
	for(int i=1;i<n-1;i++)
	{
		if(A[i]-K<0)
		continue;
		maxi=max(A[i-1]+K,A[n-1]-K);
		mini=min(A[0]+K,A[i]-K);
		ans=min(ans,maxi-mini);

	}
	
	
	return ans;
}
