#include <bits/stdc++.h> 

vector<int> countTheNumber(vector<int> &a, int n, int k) {

    vector<int> res;

    sort(a.begin(), a.end());

 

    int t = n/k;

    int count = 1;

 

    for(int i=0; i<n-1; i++){

        if(a[i+1] == a[i])

            count++;

 

        else{

            if(count >= t)

                res.push_back(a[i]);

            count = 1;

        }

    }

    if(count >= t)

        res.push_back(a[n-1]);

 

    return res;

} // link: https://www.codingninjas.com/studio/problems/elements-occur-more-than-n-k-times_1113146?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3
