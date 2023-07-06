#include <bits/stdc++.h> 
int maxAbsSum(vector<int> &arr, int n) 
{
    sort(arr.begin(),arr.end());
    vector<int>arr2;

    int i=0;
    int j=n-1;
    int ans=0;
    bool incrementStart=true;
    while(i!=j)
    {
        ans+=arr[j]-arr[i];
        if(incrementStart)
        {
            i++;
            incrementStart=false;
        }
        else
        {
            j--;
            incrementStart=true;
        }
    }
    ans+=(arr[i]-arr[0]);
    return ans;
}
