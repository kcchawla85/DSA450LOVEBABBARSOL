#include <bits/stdc++.h>
#include <vector>
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i=m-1;
	int j=n-1;
	int com=n+m-1;
	while(j>=0){
		if(i>=0 && arr1[i]>arr2[j]){
			arr1[com]=arr1[i];
			i--;
		}
		else
		{
			arr1[com]=arr2[j];
			j--;

		}
		com--;
	}
	return arr1;
}
// link : https://www.codingninjas.com/studio/problems/ninja-and-sorted-arrays_1214628?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3
