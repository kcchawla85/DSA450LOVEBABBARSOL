#include <bits/stdc++.h> 
int findPos(int N, int K, int H, vector<int>& A)
{
    int position=-1;
    for(int i=0;i<N;i++)
    {
        if(A[i]==H && abs(A[i]-A[i+1])<=K|| A[i]==H && i==(N-1))
        {
                position = i;
                return position;
        }
    }
    return position;
}
