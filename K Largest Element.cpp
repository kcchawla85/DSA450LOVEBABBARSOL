#include <bits/stdc++.h> 
vector<int> Klargest(vector<int> &a, int k, int n) {
    vector<int> arr;
    sort(a.begin(),a.end());
    int i=n-1;
    while(k>0){
        arr.push_back(a[i]);
        k--;
        i--;
    }
    reverse(arr.begin(),arr.end());
    return arr;
}
//link: https://www.codingninjas.com/studio/problems/k-largest-element_1062624?leftPanelTab=3
