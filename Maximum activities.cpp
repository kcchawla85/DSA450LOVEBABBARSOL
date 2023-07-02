#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> v;
    int n = start.size();
    for(int i=0;i<n;i++)
    {
        v.push_back({finish[i],start[i]});
    }
    sort(v.begin(),v.end());
    int count=1;
    int endlimit=v[0].first;
    for(int i=0;i<n;i++)
    {
        int s=v[i].second;
        int e=v[i].first;
        if(s>=endlimit)
        {
            count++;
            endlimit=e;
        }
    }
    return count;
}
