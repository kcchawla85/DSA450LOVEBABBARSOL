#include<bits/stdc++.h>
int minimizeMaximum(int a[], int n, int k)
{
   // Write your code here.

sort(a,a+n);

int res=a[n-1]-a[0];
int mn=a[0]+k,mx=a[n-1]-k;
 for(int i=1;i<n;i++){
  if(a[i]>=k){
   mx=max(a[n-1]-k,a[i-1]+k);
   mn=min(a[0]+k,a[i]-k);
   res=min(res,mx-mn);
  }
  
 }

return res;
}
