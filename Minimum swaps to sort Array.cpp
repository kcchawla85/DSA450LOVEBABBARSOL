#include <bits/stdc++.h>
int minSwaps(vector<int> &arr)
{
	// vector<pair<int,int>>v;
	// for(int i=0;i<arr.size();i++)
	// {
	// 	v.push_back({arr[i],i});

	// }
	// sort(v.begin(),v.end());
	// int swaps=0;
	// for(int i=0;i<arr.size();i++)
	// {
	// 	pair<int,int>p=v[i];
	// 	int value=p.first;
	// 	int index=p.second;
	// 	if(i!=index)
	// 	{
	// 		swaps++;
	// 		swap(v[i],v[index]);
	// 		i--;
	// 	}
	// }
	// return swaps;
	int count=0;
	for(int i=0;i<arr.size()-1;i++)
	{
		int min_in=i;
		for(int j=i+1;j<arr.size();j++)
		{
			if(arr[j]<arr[min_in])
			{
				min_in=j;
			}
		}
		if(min_in!=i)
		{
			swap(arr[i],arr[min_in]);
			count++;
		}
	}
	return count;

}
