#include <bits/stdc++.h> 
vector<int> findNonRepeating(vector<int> a)
{
	int res1=0, res2=0;
	int res=0;
	vector<int> v;
	for(int i=0;i<a.size();i++)
	{
		res=res^a[i];
		

	}
	int sn=res&(~(res-1));
	for(int i=0;i<a.size();i++)
	{
		if((a[i]&sn)!=0)
		{
			res1=res1^a[i];
		}
		else{
			res2=res2^a[i];
		}
	}
	v.push_back(res1);
	v.push_back(res2);
	return v;
}
