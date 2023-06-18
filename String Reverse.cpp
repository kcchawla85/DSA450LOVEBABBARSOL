#include <bits/stdc++.h> 

string stringReverse(string S) {
    int i=0;
    int j=S.size()-1;
    while(i<=j)
        {
            swap(S[i++],S[j--]);
        }
    
    return S;
  
}
