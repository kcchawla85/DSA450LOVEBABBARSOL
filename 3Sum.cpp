#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>>ans;
	sort(arr.begin(),arr.end());
	set<vector<int>>s;
	for(int i=0;i<arr.size();i++)
	{
		// if(i == 0 || arr[i] != arr[i-1]){
		int j = i + 1;
		int k = arr.size()-1;
			while(j<k)
			{	
			int sum = arr[i] + arr[j] + arr[k];
                        if (sum == K) {
                          vector<int> temp;
                          temp.push_back(arr[i]);
                          temp.push_back(arr[j]);
                          temp.push_back(arr[k]);
						  sort(temp.begin(),temp.end());
						  if(s.find(temp) == s.end())
						  {
							  ans.push_back(temp);
							  s.insert(temp);
						  }
                        //   ans.push_back(temp);
                          j++;
                          k--;
                         
                }
				else if(sum > K)k--;
				else j++;
            }
			
        }
		return ans;
}
//link: https://www.youtube.com/watch?v=DhFh8Kw7ymk&t=2040s
