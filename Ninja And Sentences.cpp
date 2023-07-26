#include <bits/stdc++.h> 
void solve(vector < vector < string > > & arr,int row, vector < vector < string > > & ans, vector<string>&s){
    if(row>=arr.size()){
        ans.push_back(s);
        return;
    }
    for(int i=0;i<arr[0].size();i++){
        s.push_back(arr[row][i]);
        solve(arr,row+1,ans,s);
        s.pop_back();
    }

}
void createSentences(vector < vector < string > > & arr, vector < vector < string > > & ans) {
    vector<string>s;
    solve(arr,0, ans, s);

}
// link: https://www.codingninjas.com/studio/problems/ninja-and-sentences_1123512?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3
