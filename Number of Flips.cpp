#include <bits/stdc++.h> 
int numberOfFlips(int a, int b)
{
    int count=0;
    int n=a^b;
    while(n!=0)
    {
        int rem=n%2;
        if(rem==1)
        {
            count++;
        }
        n=n/2;

    }
    return count;
}
