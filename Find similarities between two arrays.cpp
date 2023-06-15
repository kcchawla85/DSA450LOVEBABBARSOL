#include <bits/stdc++.h> 
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	      set <int>s;
		  for(int i=0;i<n;i++)
		  {
			  s.insert(arr1[i]);
		  }
		  for(int i=0;i<m;i++){
			  s.insert(arr2[i]);

		  }
		  int unio=0, intern=0;
		  unio=s.size();
		  intern=n+m-unio;
		  return make_pair(intern,unio);
}
