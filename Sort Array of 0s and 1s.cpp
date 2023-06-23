#include <bits/stdc++.h> 
void sort0and1(int n, vector<int> &A){
    int i=0;
    int h=n-1;
    while(i<h)
    {
        if(A[i]==0)
        {
            i++;
        }
        else if(A[h]==1)
        {
            h--;
        }
        else
        {
            swap(A[i],A[h]);
            i++;
            h--;
        }
    }

}
