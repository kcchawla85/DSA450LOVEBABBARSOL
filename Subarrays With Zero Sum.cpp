#include <bits/stdc++.h> 
int countSubarrays(int n, vector<int> &arr){
    int count=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum==0)
            {
                count++;
            }
        }
    }
    return count; 
}
