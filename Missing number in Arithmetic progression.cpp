#include <bits/stdc++.h> 
int missingNumber(vector<int> &arr, int n) 
{
    int common=min(arr[1]-arr[0],arr[2]-arr[1]);
    for(int i=1;i<n;i++)
    {
        if(arr[0]+i*common!=arr[i])
        {
            return arr[0]+i*common;
        }
    }
}
