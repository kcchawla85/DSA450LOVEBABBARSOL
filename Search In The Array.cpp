#include <bits/stdc++.h> 
vector<int> searchInTheArray(vector<int>& arr, vector<int>& queries, int n, int q)
{
    vector<int> ans;
    int i=0;
    while(i<q)
    {
        int maxi=queries[i];
        int sum=0;
        for(int k=0;k<n;k++)
        {
            if(arr[k]<=maxi)
            {
                sum+=arr[k];
            }
        }
        ans.push_back(sum);
        i++;
    }
    return ans;

   
	
}
