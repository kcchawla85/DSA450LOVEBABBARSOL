#include <bits/stdc++.h> 
int minimumSum (vector<int>& arr, int n)
{
    int mini=INT_MAX;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum>arr[i])
        {
            sum=arr[i];
        }
        mini=min(mini,sum);
    }
    return mini;
}
//hint:kadane's algorithm will be used 
