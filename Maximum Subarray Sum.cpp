#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long sum=0;
    long maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum=arr[i]+sum;
        if(sum>maxi)
        {
            maxi=sum;

        }
        if(sum<0)
        {
            sum=0;
        }

    }
    if(maxi<0)
    {
        maxi=0;
    }
    return maxi;
}
//use kadane's algorithm
