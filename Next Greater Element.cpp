#include<bits/stdc++.h>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    vector<int> v(n);
    stack<int> s;
    s.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty()&& s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            v[i]=-1;
        }
        else{
            v[i]=s.top();
        }
        s.push(arr[i]);
    }
    return v;
}
