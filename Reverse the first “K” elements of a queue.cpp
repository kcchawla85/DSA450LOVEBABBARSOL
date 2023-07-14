#include <bits/stdc++.h> 
void reverse(queue<int> &queue,int k)
{
    stack <int> s;
    for(int i=0;i<k;i++)
    {
        int temp = queue.front();
        queue.pop();
        s.push(temp);
    }
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        queue.push(temp);
    }
    int n=queue.size();
    int t=n-k;
    for(int i=0;i<t;i++){
        int temp = queue.front();
        queue.pop();
        queue.push(temp);

    }
}
// link: https://www.youtube.com/watch?v=_gJ3to4RyeQ&t=5s
