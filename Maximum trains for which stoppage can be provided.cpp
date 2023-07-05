#include <bits/stdc++.h>
bool comparator(vector<int>&v1, vector<int>&v2)
{
    return v1[1]<v2[1];
} 
int maxStop(vector<vector<int>> &trains, int n, int m)
{
    sort(trains.begin(),trains.end(),comparator);
    vector<int>dep(m+1,0);
    int platform=0;
    for(int i=0;i<n;i++)
    {
        int currplt=trains[i][2];
        if(dep[currplt]<=trains[i][0])
        {
            platform+=1;;
            dep[currplt]=trains[i][1];

        }

    }
return platform;
}
//resource link: https://www.codingninjas.com/studio/problems/maximum-trains-for-which-stoppage-can-be-provided_1169456?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3
