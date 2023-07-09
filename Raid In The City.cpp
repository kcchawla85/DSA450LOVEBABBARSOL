#include <bits/stdc++.h> 
int raidInTheCity(vector<int>& houses, int n) 
{
	vector<pair<int,int>> sell;
	vector<pair<int,int>> buy;
	int i=0,j=0;
	for(int i=0;i<n;i++)
	{
		if(houses[i]<0)
		{
			sell.push_back({houses[i], i});

        }
		else
		{
			buy.push_back({houses[i], i});
		}
	}
	int ans=0;
	while(i<buy.size() && j<sell.size())
	{
		int x=min(-sell[j].first,buy[i].first);
		buy[i].first-=x;
		sell[j].first+=x;
		int dist=abs(sell[j].second-buy[i].second);
		ans+=(x*dist);
		if(sell[j].first==0)j++;
		if(buy[i].first==0)i++;
	}
	return ans;
}
// link: https://www.codingninjas.com/studio/problems/raid-in-the-city_1170534?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3
