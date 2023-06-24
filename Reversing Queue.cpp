#include <bits/stdc++.h> 
void reverse(queue < int > & q) {
   stack<int> s;
   while(!q.empty())
   {
       int temp=q.front();
       q.pop();
       s.push(temp);
   }
   while(!s.empty())
   {
       int temp=s.top();
       s.pop();
       q.push(temp);
       
   }
}
