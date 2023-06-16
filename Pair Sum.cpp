#include <bits/stdc++.h> 
int pairSum(vector<int> &arr, int n, int target){
	int count=0;
	
	
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=i+1;j<n;j++)
	// 	{
	// 		if(arr[i]+arr[j]==target)
	// 		{
	// 			count++;
	// 		}
	// 	}
	// }
	// if(count==0)
	// {
	// 	return -1;
	// }
	// else
	// {
	// 	return count;
	// }
	 sort(arr.begin(),arr.end());        

        int i=0;

        int j=n-1;

        int ct=0;

        while (i<j) {

            int currsum = arr[i]+arr[j];

            if (currsum<target || (i>0 && arr[i]==arr[i-1])) {

                i++;

            } else if (currsum>target || (j<n-1 && arr[j]==arr[j+1])) {

                j--;

            } else {

                ct++;

                i++;

                j--;

            }

        }

        return ct==0?-1:ct;

    }
