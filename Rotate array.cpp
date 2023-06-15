#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
int main()
{
    vector<int> v;
    int size,rotate;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int k;
    cin>>k;
    rotate=size-k;
    vector<int>nums(v.size());
    for(int i=0;i<v.size();i++)
    {
        nums[(i+rotate)%v.size()]=v[i];
    }
    for(auto i:nums)
    {
        cout<<i<<" ";
    }
    return 0;
}
